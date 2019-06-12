    Info << "----------" << endl;
    scalar Tave = fvc::domainIntegrate(T).value();
    Info << "Tave = " << Tave << endl;

    volVectorField gradT("gradT", fvc::grad(T));
    
    forAll(mesh.C().boundaryField(), patchi)
    {   
        if( mesh.C().boundaryField()[patchi].patch().name() == "floor" )
        {   
            const scalarField& Ap = mesh.magSf().boundaryField()[patchi];
            scalarField dzT = gradT.boundaryField()[patchi].component(2);
            scalar Qfloor = gSum(dzT*Ap);
            Info << "Qfloor = " << Qfloor << endl;   
        }   
        if( mesh.C().boundaryField()[patchi].patch().name() == "ceiling" )
        {   
            const scalarField& Ap = mesh.magSf().boundaryField()[patchi];
            scalarField dzT = gradT.boundaryField()[patchi].component(2);
            scalar Qceiling = gSum(dzT*Ap);
            Info << "Qceiling = " << Qceiling << endl;   
        }
    }
    Info << "----------" << endl;
