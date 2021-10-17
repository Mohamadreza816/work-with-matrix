#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
//global var for dynamic memory
int num = 0;
int second_elment = 0;
//function prototype
void message();
void command(string command, struct store *mat);
int add_matrix(string command, struct store *mat);

//struct for store 2d array and name of array
struct store
{
    string name;
    int **arr;
};

int main()
{
    string request;
    message();
    getline(cin, request);
    transform(request.begin(), request.end(), request.begin(), //convert to lowercase
              [](unsigned char c)
              { return std::tolower(c); });

    store *matrix = new store[100];
    while (request != "exit")
    {
        command(request, matrix);
        message();
        getline(cin, request);
    }
}

//function for show message(abilities of program)
void message()
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
void command(string command, struct store *a_mat)
{
    if (!command.find("add matrix")) // Check if a string contains a string
    {
        command = command.substr(11); //remove add matrix
        int pos1 = command.find(' ');
        a_mat[num].name = command.substr(0, pos1); // store array names
        command = command.substr(pos1 + 1);        //remove name from command
        add_matrix(command, a_mat);
        num++;
    }
}

//add matrix
int add_matrix(string command, struct store *mat)
{

    // for (size_t i = 0; i < command.length(); i++)//a loop for chacking correct number
    // {
    //     if (isdigit(command[i]))
    //     {

    //     }else
    //     {
    //         if (command[i] == ' ')
    //         {
    //             continue;
    //         }
    //         cout << "Error...Enter a number!!!" << endl;
    //         return 0;
    //     }
    // }
    int pos = 0;
    int row = 0; //row of array
    for (pos = 0; isdigit(command[pos]); pos++)
    {
        row = row * 10 + (int(command[pos] - 48)); // convert string to number
        cout << "command[i]: " << command[pos] << endl;
    }
    int pos1 = pos; //make a copy for use in switch case
    int check = 0;
    cout << "row :" << row << endl;
    while (command[pos] != '\0')
    {
        if (isdigit(command[pos]))
        {
            check = 1; //add matrix first 3 4
        }
        if (command[pos] == '[')
        {
            if (check == 1)
            {
                check = 3; //add matrix first 3 4 [...]
                break;
            }
            else
            {
                check = 2; //add matrix first 3 [...]
                break;
            }
        }
        pos++;
    }
    cout << "check: " << check << endl;
    int column = 0; //column of array
    switch (check)
    {
    case 0:
    {
        column = row;
        mat[num].arr = new int *[column]; //make dynamically 2d array
        for (size_t i = 0; i < row; i++)
        {
            mat[num].arr[i] = new int[column];
        }
        for (size_t i = 0; i < row; i++) // fill array. input by user
        {
            for (size_t j = 0; j < column; j++)
            {
                cout << "Enter a number for"
                     << "row:" << i << "column: " << j;
                cin >> mat[num].arr[i][j];
            }
        }
        break;
    }

    case 1:
    {
        command = command.substr(pos1 + 1);
        for (pos1 = 0; isdigit(command[pos1]); pos1++)
        {
            column = column * 10 + (int(command[pos1] - 48)); // convert string to number
        }
        mat[num].arr = new int *[column]; //make dynamically 2d array
        for (size_t i = 0; i < row; i++)
        {
            mat[num].arr[i] = new int[column];
        }
        for (size_t i = 0; i < row; i++) // fill array. input by user
        {
            for (size_t j = 0; j < column; j++)
            {
                cout << "Enter a number for"
                     << "row:" << i << "column: " << j;
                cin >> mat[num].arr[i][j];
            }
        }
        break;
    }

    case 2:
    {
        column = row;
        command = command.substr(pos1 + 2);
        cout << "row: " << row << "column: " << column << endl;
        int num3 = 0;           //use for convert string to number
        int temp[row * column]; // temp array for store number of array
        cout << command << endl;
        int k = 0; // use in temp array
        int i = 0; //a var for while loop
        while (command[i] != ']')
        {
            if (isdigit(command[i]))
            {
                num3 = num3 * 10 + (int(command[i] - 48));
            }
            else
            {
                temp[k] = num3;
                num3 = 0;
                k++;
            }
            i++;
        }
        temp[k] = num3;                   // initialize last number of string
        mat[num].arr = new int *[column]; //make dynamically 2d array
        for (size_t i = 0; i < row; i++)
        {
            mat[num].arr[i] = new int[column];
        }
        k = 0;
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < column; j++)
            {
                mat[num].arr[i][j] = temp[k];
                k++;
            }
        }
        break;
    }
    case 3:
    {
        command = command.substr(pos1 + 1);
        for (size_t i = 0; i < isdigit(command[i]); i++)
        {
            column = column * 10 + (int(command[i] - 48)); // convert string to number
        }
        mat[num].arr = new int *[column]; //make dynamically 2d array
        for (size_t i = 0; i < row; i++)
        {
            mat[num].arr[i] = new int[column];
        }
        int pos2 = command.find('[');
        command = command.substr(pos + 1);
        int num3 = 0;           //use for convert string to number
        int temp[row * column]; // temp array for store number of array
        cout << command << endl;
        int k = 0; // use in temp array
        int i = 0; //a var for while loop
        while (command[i] != ']')
        {
            if (isdigit(command[i]))
            {
                num3 = num3 * 10 + (int(command[i] - 48));
            }
            else
            {
                temp[k] = num3;
                num3 = 0;
                k++;
            }
            i++;
        }
        temp[k] = num3;                   // initialize last number of string
        k = 0;
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < column; j++)
            {
                mat[num].arr[i][j] = temp[k];
                k++;
            }
        }
        break;
    }
    default:
        break;
    }
    return 0;
}