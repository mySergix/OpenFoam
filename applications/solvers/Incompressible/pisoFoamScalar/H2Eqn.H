{
     dimensionedScalar D_H2("D_H2", dimViscosity, transportProperties);
     fvScalarMatrix H2Eqn
     
     (
         fvm::ddt(H2)
       + fvm::div(phi, H2)
       - fvm::laplacian(D_H2, H2)
       ==
        fvOptions(H2)
     );
    //H2Eqn.relax();
    H2Eqn.solve();
}  
