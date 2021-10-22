{
     dimensionedScalar D_O2("D_O2", dimViscosity, transportProperties);
     fvScalarMatrix O2Eqn

     (
         fvm::ddt(O2)
       + fvm::div(phi, O2)
       - fvm::laplacian(D_O2, O2)
       ==
       fvOptions(O2)
        
        
     );

    //O2Eqn.relax();
    O2Eqn.solve();
}  
