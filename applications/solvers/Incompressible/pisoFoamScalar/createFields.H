Info<< "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading scalar field O2\n" << endl;
volScalarField O2
(
     IOobject
     (
         "O2",
         runTime.timeName(),
         mesh,
         IOobject::MUST_READ,
         IOobject::AUTO_WRITE
     ),
     mesh
 );

Info<< "Reading scalar field H2\n" << endl;
volScalarField H2
(
     IOobject
     (
         "H2",
         runTime.timeName(),
         mesh,
         IOobject::MUST_READ,
         IOobject::AUTO_WRITE
     ),
     mesh
 );

Info<< "Reading transportProperties\n" << endl;

IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

#include "createPhi.H"


label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell(p, piso.dict(), pRefCell, pRefValue);
mesh.setFluxRequired(p.name());

#include "readTransportProperties.H"

autoPtr<incompressible::turbulenceModel> turbulence
(
    incompressible::turbulenceModel::New(U, phi, laminarTransport)
);


#include "createMRF.H"
#include "createFvOptions.H"
