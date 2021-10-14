#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
//global var for dynamic memory
int num = 0;

//function prototype
void massage();
void command(string command,struct store* mat);
int add_matrix(string command ,struct store* mat ,int count);

//struct for store 2d array and name of array
struct store
{
    string name;
    int arr[][0];
};

int main()
{
    string request;
    massage();
    getline(cin, request);
    transform(request.begin(), request.end(), request.begin(), //convert to lowercase
              [](unsigned char c)
              { return std::tolower(c); });
    
    store* matrix = new store[100];
    while (request != "exit")
    {
        command(request,matrix);
        massage();
        getline(cin, request);
    }

}

//function for show massage(abilities of program)
void massage()
{
    cout << "********************" << endl;
    cout << "what do you want?" << endl;
    cout << "----------------------" << endl;
    cout << "add matrix" << endl;
    cout << "----------------------" << endl;
    cout << "is_diagonal‬‬" << endl;
    cout << "----------------------" << endl;
    cout << "is_upper_triangular‬‬" << endl;
    cout << "----------------------" << endl;
    cout << "is_lower_triangular‬‬" << endl;
    cout << "----------------------" << endl;
    cout << "is_triangular‬‬" << endl;
    cout << "----------------------" << endl;
    cout << "is_identity‬‬" << endl;
    cout << "----------------------" << endl;
    cout << "is_normal_symmetric‬‬" << endl;
    cout << "----------------------" << endl;
    cout << "is_skew_symmetric‬‬" << endl;
    cout << "----------------------" << endl;
    cout << "is_symmetric‬‬k" << endl;
    cout << "----------------------" << endl;
    cout << "exit" << endl;
    cout << "********************" << endl;
}
//end of massage function

//function for read the command
void command(string command,struct store* a_mat)
{ 
    if (!command.find("add matrix")) // Check if a string contains a string
    {
       add_matrix(command,a_mat,num);
       num++;
    }
}

//add matrix
int add_matrix(string command ,struct store* mat ,int count)
{
    command = command.substr(11);//remove add matrix
    int pos = command.find(' ');
    mat[num].name  = command.substr(0,pos);// store array names
    command = command.substr(pos + 1);
    for (size_t i = 0; i < command.length(); i++)//a loop for chacking correct number 
    {
        if (isdigit(command[i]))
        {
            
        }else
        {
            if (command[i] == ' ')
            {
                continue;
            }
            cout << "Error...Enter a number!!!" << endl;
            return 0;
        }
    }
    int pos2 = command.find(' ');//separate first number in string
    int num1 = 0;
    for (size_t i = 0; i < pos2; i++)
    {
        num1 = num1 * 10 + (int(command[i] - 48));// convert string to number
    }
    command = command.substr(pos2 + 1);
    int pos3 = command.find(' ');//separate second number in string
    int num2 = 0;
    for (size_t i = 0; i < pos2; i++)
    {
        num2 = num2 * 10 + (int(command[i] - 48));// convert string to number
    }
    for (size_t i = 0; i < num1; i++)// fill array. input by user
    {
        for (size_t j = 0; j < num2; j++)
        {
            cin>>mat[num].arr[i][j];
        }
        
    }
    
    return 0;
}