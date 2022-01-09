#include<iostream>
using namespace std;
//deklaracija na funkcii
void procesniTepmeraturiPoGrad(string grad[],int mat[100][100]);
float godisenprosek(int mat[100][100]);
void gradProsekNad(string grad[],int mat[100][100]);
void gradProsekGodisnovreme(string grad[],int mat[100][100]);
void mesecsonajvisokatemp(string mesec[],int mat[100][100]);
void gradNajgolemaProsekTemp(string grad[],int mat[100][100]);
int main()
{
	int mat[100][100];
	string grad[100];
	//deklariranje na niza od string 
	string mesec[]={"Januari","Fevruari","Mart","April","Maj","Juni","Juli","Avgust","Septemvri","Oktomvri","Noemvri","Dekemvri"};
	//ciklus za 10 gradovi
	for(int i=0;i<10;i++)
	{
		cout<<"\n Vnesete go "<<i+1<<" - ot grad : ";
		cin>>grad[i];
		//vnesuvanje na temperaturite za 12 meseci za sekoj vnesen grad
		for(int j=0;j<12;j++){
		cout<<"\n Vnesete temperatura za "<<mesec[j]<<" : ";
			cin>>mat[i][j];
		}
	}
	
	int izbor;
	//meni za izbor 
	do
	{
		cout<<endl<<endl;
		cout<<"\n =========================================";
		cout<<"\n 1. Prosecna temperatura po gradoci ";
		cout<<"\n 2. Gradovi so temperatura nad godisniot prosek";
		cout<<"\n 3. Prosecna temperatira za sekoe godisno vreme ";
		cout<<"\n 4. Mesec so najvisoka prosecna temperatura ";
		cout<<"\n 5. Grad so najvisoka prosecna temperatura vo toj mesec ";
		cout<<"\n 6. Prikaz na podatocite ";
		cout<<"\n =========================================";
		cout<<"\n Vnesete izbor : ";
		cin>>izbor;
		//izbor od meni 
		switch(izbor)
		{
			case 1:{
				//povik na funkija 
				procesniTepmeraturiPoGrad(grad,mat);
				break;
			}
			case 2:{
				//povik na funkija 
				gradProsekNad(grad,mat);
				break;
			}
			case 3:{
				//povik na funkija 
				gradProsekGodisnovreme(grad,mat);
				break;
			}
			case 4:{
				//povik na funkija 
				mesecsonajvisokatemp(mesec,mat);
				break;
			}
			case 5:{
				//povik na funkija 
				gradNajgolemaProsekTemp(grad,mat);
				break;
			}
			case 6:{
					cout<<endl<<endl;
					cout<<"================================================"<<endl;
					cout<<"  Grad  "<< "\t Temperaturi po meseci "<<endl;
					cout<<"================================================";
					for(int i=0;i<10;i++)
					{
						cout<<"\n\n "<<grad[i];
						for(int j=0;j<12;j++)
							cout<<"  "<<mat[i][j];
					}
					break;
			}
			default:cout<<"\n GRESKA "<<endl;
		}
	}while(izbor!=0);
return 0;
}
//definicija na funkcija 
void procesniTepmeraturiPoGrad(string grad[],int mat[100][100])
{
	int b[100],i,j;
	for(i=0;i<10;i++)
	{
		b[i]=0;
		for(j=0;j<12;j++)
		  b[i]=b[i]+mat[i][j];
	}
	cout<<endl<<endl;
	cout<<"================================================"<<endl;
	cout<<"  Prosecni temperaturi po gradovi "<<endl;
	cout<<"================================================";
	for(int i=0;i<3;i++)
	{
		cout<<"\n\n "<<grad[i]<<"  "<<((float)b[i]/12);
	}
	cout<<endl;
}
//definicija na funkcija 
float godisenprosek(int mat[100][100])
{
	int s=0,k=0;
	float prosek;
	//opredeluvanje na suma i broj na elementi 
	for(int i=0;i<10;i++)
	for(int j=0;j<12;j++)
	{
		s=s+mat[i][j];
		k++;
	}
	return (float)s/k;
}
//definicija na funkcija 
void gradProsekNad(string grad[],int mat[100][100])
{
	int b[100],i,j;
	for(i=0;i<10;i++)
	{
		b[i]=0;
		for(j=0;j<12;j++)
		  b[i]=b[i]+mat[i][j];
	}
	cout<<endl<<endl;
	cout<<"==============================================================="<<endl;
	cout<<"  Gradovi so povisoka prosecna temperatura od godisniot prosek "<<endl;
	cout<<"==============================================================="<<endl;
	for(i=0;i<3;i++)
	if(((float)b[i]/12)>godisenprosek(mat))
	   cout<<grad[i]<<"  "<<((float)b[i]/12)<<endl;
}
//definicija na funkcija 
void gradProsekGodisnovreme(string grad[],int mat[100][100])
{
	int s1,s2,s3,s4;
	cout<<endl<<endl;
	cout<<"==============================================================="<<endl;
	cout<<" Prosek na temperaturi po godisno vreme za sekoj grad "<<endl;
	cout<<"==============================================================="<<endl;
	cout<<"\t grad \t Zima \t Proelt \t leto \t esen "<<endl;
	for(int i=0;i<10;i++)
	{
		s1=0;
		s2=0;
		s3=0;
		s4=0;
		for(int j=0;j<12;j++)
		{
			if(j==12||j==1|| j==2)
				s1=s1+mat[i][j];
			if(j>=3 && j<=5)
				s2=s2+mat[i][j];
			if(j>=6 && j<=8)
				s3=s3+mat[i][j];
			if(j>=9 && j<=11)
				s4=s4+mat[i][j];
		}
		cout<<"\t"<<grad[i]<<"\t"<<s1<<"\t"<<s2<<"\t"<<s3<<"\t"<<s4<<endl;
	}
}
//definicija na funkcija 
void mesecsonajvisokatemp(string mesec[],int mat[100][100])
{
	int b[100],i,j,pmax;
	float prosek[100],max;
	for(i=0;i<12;i++)
	{
		b[i]=0;
		for(j=0;j<10;j++)
		  b[i]=b[i]+mat[j][i];
	}
	for(int i=0;i<12;i++)
		prosek[i]=(float)b[i]/3;
	max=prosek[0];
	pmax=0;
	for(int i=0;i<12;i++)
	if(prosek[i]>max)
	{
		max=prosek[i];
		pmax=i;
	}
	cout<<endl<<endl;
	cout<<"================================================"<<endl;
	cout<<"  Mesec so najvisoka prosecn temperatua e "<<mesec[pmax]<<endl;
	cout<<"================================================"<<endl<<endl;
}
//definicija na funkcija 
void gradNajgolemaProsekTemp(string grad[],int mat[100][100])
{
	int b[100],i,j,pmax;
	float prosek[100],max;
	for(i=0;i<10;i++)
	{
		b[i]=0;
		for(j=0;j<12;j++)
		  b[i]=b[i]+mat[i][j];
	}
	for(i=0;i<3;i++)
	prosek[i]=(float)b[i]/12;
	max=prosek[0];
	pmax=0;
	for(i=0;i<3;i++)
	if(prosek[i]>max)
	{
		max=prosek[i];
		pmax=i;
	}
	cout<<endl<<endl;
	cout<<"==============================================================="<<endl;
	cout<<"  Gradot so najgolema prosecna temperatura e  "<<grad[pmax]<<endl;
	cout<<"==============================================================="<<endl;

}
