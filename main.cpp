#include "EasyBMP.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    BMP Output;
    int Nx=0,Ny=0,Nnonzeor;

    string FileName="./inout/matrix.bmp";
    char*   filename=(FileName.data());
    
    printf("We must put the A.mtx in the inout directory and run the main program good luck ")  ;
       
     string FileName2 ="./inout/A.mtx";
     fstream infile1(FileName2, ios::in);
            
        infile1.ignore(1000, '\n') ;
        infile1.ignore(1000, '\n') ;
        infile1.ignore(1000, '\n') ;
        infile1.ignore(1000, '\n') ;
        infile1.ignore(1000, '\n') ;
        infile1>>Nx>>Nx>>Nnonzeor;
        Ny=Nx;
        Output.SetSize(Nx,Ny);
        Output.SetBitDepth( 24 );
            
        printf("Matrix A has row %d  and non-zero %d :\n",Nx,Nnonzeor)  ;
      for(int k=0;k<Nnonzeor;k++)   
       {   int i,j;
       double v;
           infile1>>i>>j>>v;
           i=i-1;j=j-1;
           if(j==i and i!=0)
           {Output(j,i)->Red=0;
           Output(j,i)->Green=0;
           Output(j,i)->Blue= 0;
           Output(j,i)->Alpha=255;      
           }
           else
           {Output(j,i)->Red=255;
           Output(j,i)->Green=0;
           Output(j,i)->Blue= 0;
           Output(j,i)->Alpha=255;      
           }  
            if(j==i and i==0)
           {Output(j,i)->Red=0;
           Output(j,i)->Green=0;
           Output(j,i)->Blue= 255;
           Output(j,i)->Alpha=255;      
           }    
          }
    Output.WriteToFile(filename );
}
