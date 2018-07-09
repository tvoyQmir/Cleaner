#include <iostream>
#include <cstdlib>
#include <ctime>

void ShowBorderArray(const int ROW, const int COL,char arr[][12]);
void FillBorderArray(const int ROWS, const int COLS,char array[][12]);
int GameOver();
void randBlocker(int &rand_a,int &rand_b,char array[][12]);
void Points(int &points);



int main() {
    int points = 0;
    srand(time(NULL));
    int rand_a = 0;
    int rand_b = 0;
    const int ROWS = 12;
    const int COLS = 12;

    char array[ROWS][COLS];

    FillBorderArray(ROWS, COLS, array);

    int a = 5;
    int b = 5;

    array[a][b] = '*';

    ShowBorderArray(ROWS, COLS, array);


    int count;
    int h = 0;
    do
        {
            if(a == 0 || b == 0 || a == 12 || b == 12 )
            {
                GameOver();
                exit(0);
            }

           randBlocker(rand_a,rand_b,array);

            count = getchar();

            switch (count) {
                case  87 :
                    //UP

                    {

                        if(array[a-1][b] == '#')
                        {
                           std::cout<<"Points plus"<<std::endl;
                            points++;
                        }
                        array[a][b] = ' ';
                        a--;
                        array[a][b] = '*';
                        Points(points);
                       ShowBorderArray(ROWS, COLS, array);
                        break;

                    }

                    case 65:

                        //left
                        {

                            if(array[a][b-1] == '#')
                            { std::cout<<"Points plus"<<std::endl;

                                points++;
                            }
                            array[a][b] = ' ';
                            b--;
                            array[a][b] = '*';
                            Points(points);
                            ShowBorderArray(ROWS, COLS, array);
                            break;



                        }


                        case 68:

                            //right

                            {
                                if(array[a][b+1] == '#')
                                { std::cout<<"Points plus"<<std::endl;

                                    points++;
                                }
                                array[a][b] = ' ';
                                b++;
                                array[a][b] = '*';
                                Points(points);
                                ShowBorderArray(ROWS, COLS, array);
                                break;


                            }


                            case 83:
                                //DOWN

                                {

                                    if(array[a+1][b] == '#')
                                    { std::cout<<"Points plus"<<std::endl;
                                        points++;
                                    }
                                    array[a][b] = ' ';
                                    a++;
                                    array[a][b] = '*';
                                    Points(points);
                                    ShowBorderArray(ROWS, COLS, array);
                                    break;


                                }


                                default:

                                    {

                                        std::cout<<"Press E for quit."<<std::endl;
                                        break;

                                    }
                                    }

        }while (count== 'E');
    return 0;
}

void ShowBorderArray(const int ROWS, const int COLS,char arr[][12])
{
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS ; ++j) {
            std::cout << arr[i][j]<<"\t";
        }
        std::cout << std::endl;
    }
}

void FillBorderArray(const int ROWS, const int COLS,char array[][12])
{
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS ; ++j) {

            if(i==0||i==(ROWS-1))
            {
                array[i][j] = '#';
            }
            else
                {
                    if(j==0||j==(COLS-1))
                    {
                        array[i][j] = '#';
                    }
                    else array[i][j] = ' ';
                }


        }
        std::cout << std::endl;

    }
}

int GameOver()
{
    std::cout<<"Game over. You lose"<<std::endl;
    return 1;
}

void randBlocker(int &rand_a,int &rand_b,char array[][12])
{
    M1:
    rand_a=rand()%10;
    rand_b=rand()%10;
    if(  array[rand_a][rand_b] == '#')
    {
        goto M1;

    }
    array[rand_a][rand_b]='#';

}

void Points(int &points)
{
    std::cout<<"You have "<<points<<" point(s)."<<std::endl;
}