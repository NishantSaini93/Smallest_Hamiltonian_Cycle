#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;


int main(int argc, char* argv[]){
    
    
    ifstream in(argv[1]);
    
    if(!in){
        cout<<"Cannot open input file;"<<endl;
        return -1;
    		}
    
   ofstream out(argv[2]);
    
    if(!out){
        cout<<"Cannot open  output file;"<<endl;
        return -1;
    		}
    
    int M; 
    in>>M;

     
    
for(int i=0;i<M;i++)
{
    int Vertices;
	
     	in>>Vertices;
    	int Edges;
     

     		in>>Edges;
			int weights[20][20];

		for (int i = 0; i < 20; i++)
   			 for (int j = 0; j < 20; j++)
      				weights[i][j] = 0;


int firstnode[Edges];

int secondnode[Edges];

int tempw[Edges];

		for(int i=0;i<Edges;i++)
			{
			int temp1,temp2,temp3;


			in>>temp1;


			in>>temp2;


			in>>temp3;


				weights[temp1][temp2]=temp3;


				weights[temp2][temp1]=weights[temp1][temp2];


				}

int optimal=99999999;  
int listn[Vertices];


			for(int i=0;i<Vertices;i++)
				{
				listn[i]=i;
				}

				sort (listn,listn+Vertices);

				 do {int rout=0;
						for(int i=0;i<3;i++)
							{
							rout=rout+weights[listn[i]][listn[i+1]];


							}

				rout=rout+weights[listn[3]][listn[0]];




						if(rout<optimal)
							{
							optimal=rout;
							}
  

					} 
					while (next_permutation(listn,listn+Vertices));

out << optimal<<"\n";

   


     
}      
    
    return 0;
}
