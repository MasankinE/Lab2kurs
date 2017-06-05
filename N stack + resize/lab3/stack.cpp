#include <iostream>

template <class T>
class Stack
{
private:
     
   
public:
		T * arr;
        int size, len;
		int* head; 
		int* lenn;
		int* sizn;
		int NN;

        Stack()
        {
				NN=1;
                len = 0;
				size = 10;
                arr = new T[size+1];
				head = new int[size];
				lenn = new int[size];
				sizn = new int[size];
				for (int i=0; i<size; i++)
				{
					arr[i]=0;
					head[i]=0;
					lenn[i]=0;
					sizn[i]=0;
				}
        }


		void StackPrn() //debug
        {
				cout<<"( ";
				for (int i=0; i<size; i++)
				{ 
					cout<<arr[i]<<" ";
					for (int l=0; l<NN; l++)
						if (head[l]==i+1)
						cout<<")( ";
				}
				cout<<" )";
				cout<<endl;
				for (int i=0; i<NN; i++)
				{ 
					cout<<head[i]<<" ";
				}
				cout<<endl;
				for (int i=0; i<NN; i++)
				{ 
					cout<<lenn[i]<<" ";
				}
				cout<<endl;
					for (int i=0; i<NN; i++)
				{ 
					cout<<sizn[i]<<" ";
				}
				cout<<endl;
			//	cout<<size<<" "<<endl;
				cout<<endl;
        }



		void StackSet(int n)
        {
				NN=n;
				head = new int[n];
				lenn = new int[n];
				sizn = new int[n];

				head[0]=0;
				lenn[0]=1;
				len = 0;

				for (int i=0; i<n; i++)
				sizn[i]=0;

				for (int i=1; i<n; i++)
				head[i]=(size/n)*i;

				for (int i=0; i<n-1; i++)
				lenn[i]=head[i+1]-head[i];
				lenn[n-1]=size-head[n-1];

				//rebalance empty
				for (int j=0; j<n-1; j++)
				{
					for (int i=0; i<n-1; i++)
						if (lenn[i+1]>lenn[i])
						{
							head[i+1]++;
							lenn[i]++;
							//bezymnii kostil
							for (int k=0; k<n-1; k++)
							lenn[k]=head[k+1]-head[k];
							lenn[n-1]=size-head[n-1];
						}
					lenn[n-1]=size-head[n-1];
				}

		}

        ~Stack()
        {  delete[] arr; }
 
        int Size()
        {    return len; }

		int Size(int x)
        {
                return len[x-1];
        }

        void Push(int x, int z)
        {
			if (sizn[x]<lenn[x])
				{
					arr[head[x]+sizn[x]]=z;
					sizn[x]++;
					len++;
					Rebalance();
				}
			
			/*else
			{
				//cout<<x<<" full, "<<z<<" -"<<endl;

			}*/
			if (size==len+NN)
				{
					resize();
					Rebalance();
				}
        }

		void resize()
        {
                T* new_arr = new int[size+NN];
                for (int i = 0; i<size; i++) 
					new_arr[i] = arr[i];
				for (int i = size; i<size+NN; i++) 
					new_arr[i] = 0;

                delete[] arr;
                size = size+NN;
                arr = new_arr;		
        }



	void Rebalance()
        {
		for (int j=0; j<NN-1; j++) //гоняем нули
{
			for (int i=0; i<NN-1; i++)
			{
				if (lenn[i+1]-sizn[i+1]>lenn[i]-sizn[i])
					{
						for (int k=head[i+1]+sizn[i+1]-1; k>head[i+1]-1; k--)
						arr[k+1]=arr[k];

						arr[head[i+1]]=0;

						//if (head[i+1]+1<size)
						head[i+1]++;

						lenn[i]++;
						lenn[i+1]--;
						//bezymnii kostil
						for (int k=0; k<NN-1; k++)
						lenn[k]=head[k+1]-head[k];

						lenn[NN-1]=size-head[NN-1];
					}
			}
			//ring
				if ((lenn[0]-sizn[0])>(lenn[NN-1]-sizn[NN-1]))
					{
						for (int k=head[1]-1; k<head[NN-1]+sizn[NN-1]; k++)
							if (k+1<size)
						arr[k]=arr[k+1];
						//arr[size-1]=0;

						arr[head[NN-1]+sizn[NN-1]]=0;
						lenn[0]--;
						lenn[NN-1]++;

						for (int k=1; k<NN; k++)
						head[k]--;
						
						//bezymnii kostil
						for (int k=0; k<NN-1; k++)
						lenn[k]=head[k+1]-head[k];

						lenn[NN-1]=size-head[NN-1];
					}	
}
	}


		void StackPrnt(int z)
        {
				cout<<"Stack "<<z<<" :";
				for (int i=head[z]; i<head[z]+sizn[z]; i++)
				{ 
					cout<<arr[i]<<" ";
				}
				cout<<endl;
        }

		void StackPrntAll()
        {
		cout<<"( ";
				for (int i=0; i<size; i++)
				{ 
					cout<<arr[i]<<" ";
					for (int l=0; l<NN; l++)
						if (head[l]==i+1)
						cout<<")( ";
				}
				cout<<" )";
				cout<<endl;
		}

		T Get(int z)
        {
				int temp=0;
				if (sizn[z]>0)
					{
					temp=arr[head[z]+sizn[z]-1];
					sizn[z]--;
					arr[head[z]+sizn[z]]=0;
					Rebalance();
					return temp;
					}
				else
					{
					cout<<z<<" empty"<<endl;
					return -1;
					}
        }

  

		void Dopzadanie()
        {
			cout<<"Dopzadanie"<<endl;
			for (int z=0; z<NN; z++)
			{
				cout<<"Stack "<<z<<" :";
				for (int i=head[z]; i<head[z]+sizn[z]; i++)
				{ 
					cout<<arr[i]+rand()%10<<" ";
				}
				cout<<endl;
			}
        }

};



using namespace std;
int main(int argc, char* argv[])
{
	//int
    Stack<int> S;
	//set n
	int n=4;
	S.StackSet(n);
	
	//Push It To The Limit~
	cout<<"Gen rnd"<<endl;
	for (int i=1; i<17; i++)
	{
		S.Push(rand()%n, i); // x, z		
		S.StackPrntAll();

	}
	cout<<endl;

	for (int i=0; i<n; i++)
	S.StackPrnt(i);
	cout<<endl;

	//вывод из стека
	for (int j=0; j<5; j++)
	{
		cout<<endl;
		cout<<"Zabrali iz steka 1 - "<<S.Get(1)<<endl;
		S.StackPrntAll();
	}
	cout<<endl;

	//dopzadanie - метод на вывод
	S.Dopzadanie();
	cout<<endl;
	

	system ("pause");
	return 0;
}