#include <iostream>
#define Info
class  Array
        {
public:
            int ROW ;
            int COL ;
            int **arr;

    Array(int valueR, int valueC)
            {
                this-> ROW = valueR;
                this-> COL = valueC;
                this-> arr = new int*[ROW];
                for (int i = 0; i <ROW ; ++i) {

                    this-> arr[i] = new int[COL];
                }

                #ifdef Info

                std::cout<<"KONSTR  "<<this<<std::endl;

                #endif


            }



    void FillArray()
    {
        for (int i = 0; i < ROW ; ++i) {
            for (int j = 0; j < COL; ++j) {


                arr[i][j] = rand() % 10;
            }
        }
    }

 void Change(Array & other)
    { int a = other.COL;
        this->COL = other.ROW;
        this->ROW = a;


       int ** arr1 = new int*[ROW];
        for (int i = 0; i <ROW ; ++i) {

            arr1[i] = new int[COL];
        }

        for (int i = 0, b = 0; i <ROW ; i++, b++) {
            for (int j = 0, a = 0; j <COL ; j++, a++) {


              arr1[i][j] = other.arr[a][b];

            }

        }

delete[] arr;

        this->arr = arr1;
    }

  void ShowArray()
  {
      for (int i = 0; i < ROW ; ++i) {
          for (int j = 0; j < COL; ++j) {

              std::cout<<arr[i][j] <<"\t";
          }

          std::cout<<std::endl;
      }

  }
    void ShowInfo()
    {
            std::cout <<"This is another array"<< std::endl;
    }
    ~Array(){

        #ifdef Info

        std::cout << "\nDISTR " << this << std::endl;

        #endif
                delete[] arr;
            }

};
int main() {

    Array arr(2,5);

    arr.FillArray();

    arr.ShowArray();

    arr.ShowInfo();

    arr.Change(arr);

    arr.ShowArray();


    return 0;
}