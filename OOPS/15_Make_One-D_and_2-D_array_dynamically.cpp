#include<iostream>
using namespace std;
class array
{
    public:
    //1D array
    int *arr1d;
    //2D array
    int **arr2d;
    int row;
    int col;
    //constructor to set rows and columns
    array(int row,int col)
    {
        this->row=row;
        this->col=col;
        arr1d=new int[row];
        arr2d=new int*[row];
    }
    //make 1D array
    void setarray1d()
    {
        cout<<"Enter the array"<<endl;
        for(int i=0;i<row;i++)
        {
            cin>>arr1d[i];
        }
    }
    //print 1D array
    void getarray1d()
    {
        for(int i=0;i<row;i++)
        {
            cout<<arr1d[i]<<" ";
        }
    }
    //make 2D array
    void setarray2d()
    {
        cout<<"Enter the array"<<endl;
        for(int i=0;i<row;i++)
        {
            //here we make a 1D array every time as size of column
            arr2d[i]=new int[col];
            //assign values in new 1D array
            for(int j=0;j<col;j++)
            {
                cin>>arr2d[i][j];
            }
        }
    }
    //print 2D array
    void getarray2d()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<arr2d[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    ~array()
    {
        //deallocate array
        delete[]arr1d;
        for(int i=0;i<row;i++)
        {
            delete[] arr2d[i];
        }
        delete[]arr2d;
}

};
int main()
{
    array arr(4,5);
    arr.setarray1d();
    arr.getarray1d();
    // arr.setarray2d();
    // arr.getarray2d();

}