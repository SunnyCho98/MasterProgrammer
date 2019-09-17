#include <iostream>
#include <string>
#include <vector>

using namespace std;
///////////////////////////////
//GAME PROJECT/////////////////
//GET THE NUMBERS//////////////
//To kill off DR Dhoom's plan//


//Functions being used in game
void display();
void displayLevels(int &level, int a, int b, int c);
int* returnTheCode(int &difficulty, int levles);
int isError(int sum, int product, int a, int b, int c);
void errorMessage();
////////////////////////////////

///////////////////////////////////////////
//Displays the beginning message to the game
void display()
{
    cout<< "WELCOME TO RANDY'S SPY GAME!!" << endl;
    cout<< "THE RULES TO THIS GAME FOLLOW:" << endl;
    cout<< "RULE 1: GUESS THE CODE AND NO INTERNET" << endl;
    cout<< "RULE 2: DON'T GET ANY OUTSIDE HELP!!!" << endl;
    cout<< "IF YOU CANNOT GUESS THE CODE, DR DHOOM" << endl;
    cout<< "WILL DESTROY THE WORLD SO GET THINKING!" << endl;
}
//displays levels of the program
void displayLevels(int &level, int *code)
{
    int sum = code[0] + code[1] + code[2];
    int product = code[0] * code[1] * code[2];
    cout<<"Welcome to level: " << level << endl;
    cout<<"The challenge of this Level is:" << endl;
    cout<<"What three integers multiply to: " << product << endl;
    cout<<"What three integers add to: " << sum << endl;
    cout<<"Enter the code: " << endl;
}
//returns pointer to three numbers
int* returnCode(int &difficulty, int levels)
{
    srand(time(NULL));
    int *code_answer = nullptr;
    code_answer= new int[3];

    code_answer[0] = (rand() % difficulty) +  1;
    code_answer[1] = (rand() % difficulty) +  1;
    code_answer[2] = (rand() % difficulty) +  1;

    difficulty = levels * difficulty * 2;

    return code_answer;
}
int isError(int sum, int product, int a, int b, int c)
{
    int sum_user = a + b + c;
    int product_user = a * b * c;

    if( sum_user == sum || product_user == product)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

void errorMessage()
{
    cout<<"Wrong input!! Please TRY AGAIN!!" << endl;
    cout<<"Enter the code again:";
}
int main()
{
    //Variables 
    int difficulty = 5;
    int levels = 1; //will add more as user continues
    int first_num = 0;
    int second_num = 0;
    int third_num = 0;

    //////////////////////////////////Making the code here//////////////
    int *code = nullptr;
    /////////////////////////////////////////////////////////////////////

    //Begins game by displaying initial message 
    display();

    while(levels != 11)
    {
        code = returnCode(difficulty, levels);  //returns a special made code
        int sum = code[0] + code[1] + code[2];  //is sum of this code
        int product = code[0] * code[1] * code[2]; //is pro
        displayLevels(levels, code);
        cin >> first_num >> second_num >> third_num;
        if(first_num == 0)
        {
            break;
        }
        int user_sum = first_num + second_num + third_num;
        int user_product = first_num * second_num * third_num;
        while(user_sum != sum || user_product != product)
        {
           errorMessage();
           cin>>first_num >> second_num >> third_num;
           user_sum = first_num + second_num + third_num;
           user_product = first_num * second_num * third_num;
           
        }
        cout<< "Congrats on getting the answer right!!" << endl;
        cout<<"Please continue to the next level" << endl;
        levels++;
        


    }
    if (levels == 11)
        cout<<"Congrats on winning.... you are a legend" << endl;
    else 
        cout<<"Congrats on quitting.... you are a loser" << endl;

    delete code;
    return 0;
}