#include <iostream>
#include <iomanip>
using namespace std;
//global variable for dynamically struct
int num = 0;

//---------------------------------------------
// //function prototype
void message();
bool command(string command, struct store *mat);
bool is_diagonal(string command, struct store *mat);
bool is_triangular(string command, struct store *mat);
bool is_identity(string command, struct store *mat);
bool is_symmetrick(string command, struct store *mat);
bool inverse(string command, struct store *mat);
bool show(string command, struct store *mat);
bool delete_matrix(string command, struct store *mat);
bool change(string command, struct store *mat);
int tyid(string command);
bool change(string command, struct store *mat);
bool exit(struct store *mat);
//---------------------------------------------

//store for store 2d array
struct store
{
    string name;
    int row;
    int column;
    int typy; //identity data type in add matrix function
    int **arri;
    double **arrd;
    char **arrc;
    string **arrs;
};
/*******************************************************************/
/*******************************************************************/
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
    cout << "inverse‬‬" << endl;
    cout << "----------------------" << endl;
    cout << "show" << endl;
    cout << "----------------------" << endl;
    cout << "change" << endl;
    cout << "----------------------" << endl;
    cout << "delete" << endl;
    cout << "----------------------" << endl;
    cout << "exit" << endl;
    cout << "********************" << endl;
}
//end of massage function
/*******************************************************************/
/*******************************************************************/
//tyid function
int tyid(string command)
{
    string temp = command;
    int check = 3; //char
    if (isdigit(temp[0]))
    {
        if (temp.find('.') < 20)
        {
            check = 2; //double
        }
        else
        {
            check = 1; //int
        }
    }
    if (!isdigit(temp[0]))
    {
        int pos = temp.find(',');
        temp = temp.substr(0, pos);
        if (temp.length() > 1)
        {
            check = 4; //string
        }
    }
    return check;
}
//end of tyid function
/*******************************************************************/
/*******************************************************************/
//add matrix function
int add_matrix(string command, struct store *mat)
{
    command = command.substr(11); //remove add matrix from command
    int x = command.find(' ');
    for (size_t i = 0; i < num; i++)
    {
        if (mat[i].name == command.substr(0, x))
        {
            cout << "input another name for matrix!" << endl;
            return false;
        }
    }
    mat[num].name = command.substr(0, x); // store array names
    command = command.substr(x + 1);      //remove name from command

    int pos = 0;
    int row = 0; //row of array
    for (pos = 0; isdigit(command[pos]); pos++)
    {
        row = row * 10 + (command[pos] - 48); // convert string to number
    }
    int pos1 = pos; //make a copy for use in switch case
    int check = 0; // add matrix first 2
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
    int column = 0; //column of array
    switch (check)
    {
    case 0:
    {
        column = row;
        mat[num].row = row;
        mat[num].column = column;
        cout << "Enter a number for"
             << " row: " << 1 << " column: " << 1 << " ---> ";//get first home of array
        string temp; //use recognize datatype of array
        cin >> temp;
        mat[num].typy = tyid(temp); //recognize data type
        if (mat[num].typy == 1)
        {
            int first = stoi(temp);
            mat[num].arri = new int *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arri[i] = new int[column];
            }
            mat[num].arri[0][0] = first;
            int j = 0;
            for (size_t i = 0; i < row; i++) // fill array. input by user
            {
                if (i == 0)
                {
                    j = 1;
                }
                else
                {
                    j = 0;
                }
                for (j; j < column; j++)
                {
                    cout << "Enter a number for"
                         << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
                    cin >> mat[num].arri[i][j];
                }
            }
        }
        if (mat[num].typy == 2)
        {
            double first = stod(temp);
            mat[num].arrd = new double *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arrd[i] = new double[column];
            }
            mat[num].arrd[0][0] = first;
            int j = 0;
            for (size_t i = 0; i < row; i++) // fill array. input by user
            {
                if (i == 0)
                {
                    j = 1;
                }
                else
                {
                    j = 0;
                }
                for (j; j < column; j++)
                {
                    cout << "Enter a number for"
                         << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
                    cin >> mat[num].arrd[i][j];
                }
            }
        }
        if (mat[num].typy == 3)
        {
            mat[num].arrc = new char *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arrc[i] = new char[column];
            }
            mat[num].arrc[0][0] = temp[0];
            int j = 0;
            for (size_t i = 0; i < row; i++) // fill array. input by user
            {
                if (i == 0)
                {
                    j = 1;
                }
                else
                {
                    j = 0;
                }
                for (j; j < column; j++)
                {
                    cout << "Enter a number for"
                         << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
                    cin >> mat[num].arrc[i][j];
                }
            }
        }
        if (mat[num].typy == 4)
        {
            mat[num].arrs = new string *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arrs[i] = new string[column];
            }
            int j = 0;
            mat[num].arrs[0][0] = temp;
            j++;
            for (size_t i = 0; i < row; i++) // fill array. input by user
            {
                if (i == 0)
                {
                    j = 1;
                }
                else
                {
                    j = 0;
                }
                for (j; j < column; j++)
                {
                    cout << "Enter a number for"
                         << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
                    cin >> mat[num].arrs[i][j];
                }
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
        mat[num].row = row;
        mat[num].column = column;
        cout << "Enter a number for"
             << " row: " << 1 << " column: " << 1 << " ---> ";//get first home of array
        string temp; //use recognize datatype of array
        cin >> temp;
        mat[num].typy = tyid(temp);
        if (mat[num].typy == 1)
        {
            int first = stoi(temp);
            mat[num].arri = new int *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arri[i] = new int[column];
            }
            mat[num].arri[0][0] = first;
            int j = 0;
            for (size_t i = 0; i < row; i++) // fill array. input by user
            {
                if (i == 0)
                {
                    j = 1;
                }
                else
                {
                    j = 0;
                }
                for (j; j < column; j++)
                {
                    cout << "Enter a number for"
                         << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
                    cin >> mat[num].arri[i][j];
                }
            }
        }
        if (mat[num].typy == 2)
        {
            double first = stod(temp);
            mat[num].arrd = new double *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arrd[i] = new double[column];
            }
            mat[num].arrd[0][0] = first;
            int j = 0;
            for (size_t i = 0; i < row; i++) // fill array. input by user
            {
                if (i == 0)
                {
                    j = 1;
                }
                else
                {
                    j = 0;
                }
                for (j; j < column; j++)
                {
                    cout << "Enter a number for"
                         << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
                    cin >> mat[num].arrd[i][j];
                }
            }
        }
        if (mat[num].typy == 3)
        {
            mat[num].arrc = new char *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arrc[i] = new char[column];
            }
            mat[num].arrc[0][0] = temp[0];
            int j = 0;
            for (size_t i = 0; i < row; i++) // fill array. input by user
            {
                if (i == 0)
                {
                    j = 1;
                }
                else
                {
                    j = 0;
                }
                for (j; j < column; j++)
                {
                    cout << "Enter a number for"
                         << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
                    cin >> mat[num].arrc[i][j];
                }
            }
        }
        if (mat[num].typy == 4)
        {
            mat[num].arrs = new string *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arrs[i] = new string[column];
            }
            int j = 0;
            mat[num].arrs[0][0] = temp;
            j++;
            for (size_t i = 0; i < row; i++) // fill array. input by user
            {
                if (i == 0)
                {
                    j = 1;
                }
                else
                {
                    j = 0;
                }
                for (j; j < column; j++)
                {
                    cout << "Enter a number for"
                         << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
                    cin >> mat[num].arrs[i][j];
                }
            }
        }
        break;
    }
    case 2:
    {
        column = row;
        mat[num].row = row;
        mat[num].column = column;
        command = command.substr(pos1 + 2);
        int pos2 = command.find(',');
        string temp = command.substr(0, pos2);
        mat[num].typy = tyid(temp);
        if (mat[num].typy == 1)
        {
            int num3 = 0;           //use for convert string to number
            int fake[row * column]; // temp array for store number of array
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
                    fake[k] = num3;
                    num3 = 0;
                    k++;
                }
                i++;
            }
            fake[k] = num3;                    // initialize last number of string
            mat[num].arri = new int *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arri[i] = new int[column];
            }
            k = 0;
            for (size_t i = 0; i < row; i++)
            {
                for (size_t j = 0; j < column; j++)
                {
                    mat[num].arri[i][j] = fake[k];
                    k++;
                }
            }
        }
        if (mat[num].typy == 2)
        {
            string num3;               //use for convert string to number
            double num_double = 0;     //use for convert string to number
            double fake[row * column]; // temp array for store number of array
            int k = 0; // use in temp array
            int i = 0; //a var for while loop
            int j = 0; //use for fake array
            while (true)
            {
                if (command[i] == ']')
                {
                    num3 = command.substr(k, i);
                    fake[j] = stod(num3);
                    break;
                }

                if (command[i] == ',')
                {
                    num3 = command.substr(k, i);
                    k = i + 1;
                    fake[j] = stod(num3);
                    j++;
                }
                i++;
            }
            mat[num].arrd = new double *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arrd[i] = new double[column];
            }
            k = 0;
            for (size_t i = 0; i < row; i++)
            {
                for (size_t j = 0; j < column; j++)
                {
                    mat[num].arrd[i][j] = fake[k];
                    k++;
                }
            }
        }
        if (mat[num].typy == 4)
        {
            string fake[row * column]; // temp array for store number of array
            int k = 0; // use in temp array
            int i = 0; //a var for while loop
            int j = 0;
            while (true)
            {
                if (command[i] == ']')
                {
                    fake[j] = command.substr(k, i - k);
                    break;
                }
                if (command[i] == ',')
                {
                    fake[j] = command.substr(k, i - k);
                    k = i + 1;
                    j++;
                }
                i++;
            }
            mat[num].arrs = new string *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arrs[i] = new string[column];
            }
            k = 0;
            for (size_t i = 0; i < row; i++)
            {
                for (size_t j = 0; j < column; j++)
                {
                    mat[num].arrs[i][j] = fake[k];
                    k++;
                }
            }
        }
        if (mat[num].typy == 3)
        {
            char num3;               //use for convert string to number
            char fake[row * column]; // temp array for store number of array
            int k = 0; // use in temp array
            int i = 0; //a var for while loop
            int j = 0;
            while (true)
            {
                if (command[i] == ']')
                {
                    num3 = command[i - 1];
                    fake[j] = num3;
                    break;
                }
                if (command[i] == ',')
                {
                    num3 = command[i - 1];
                    k = i + 1;
                    fake[j] = num3;
                    j++;
                }
                i++;
            }
            mat[num].arrc = new char *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arrc[i] = new char[column];
            }
            k = 0;
            for (size_t i = 0; i < row; i++)
            {
                for (size_t j = 0; j < column; j++)
                {
                    mat[num].arrc[i][j] = fake[k];
                    k++;
                }
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
        mat[num].row = row;
        mat[num].column = column;
        int pos2 = command.find('[');
        command = command.substr(pos2 + 1);
        mat[num].typy = tyid(command);
        if (mat[num].typy == 1)
        {
            int num3 = 0;           //use for convert string to number
            int fake[row * column]; // temp array for store number of array
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
                    fake[k] = num3;
                    num3 = 0;
                    k++;
                }
                i++;
            }
            fake[k] = num3;                    // initialize last number of string
            mat[num].arri = new int *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arri[i] = new int[column];
            }
            k = 0;
            for (size_t i = 0; i < row; i++)
            {
                for (size_t j = 0; j < column; j++)
                {
                    mat[num].arri[i][j] = fake[k];
                    k++;
                }
            }
        }
        if (mat[num].typy == 2)
        {
            string num3;               //use for convert string to number
            double fake[row * column]; // temp array for store number of array
            int k = 0;                 // use in temp array
            int i = 0;                 //a var for while loop
            int j = 0;
            while (true)
            {
                if (command[i] == ']')
                {
                    num3 = command.substr(k, i);
                    fake[j] = stod(num3);
                    break;
                }

                if (command[i] == ',')
                {
                    num3 = command.substr(k, i);
                    k = i + 1;
                    fake[j] = stod(num3);
                    j++;
                }
                i++;
            }
            mat[num].arrd = new double *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arrd[i] = new double[column];
            }
            k = 0;
            for (size_t i = 0; i < row; i++)
            {
                for (size_t j = 0; j < column; j++)
                {
                    mat[num].arrd[i][j] = fake[k];
                    k++;
                }
            }
        }

        if (mat[num].typy == 4)
        {
            string fake[row * column]; // temp array for store number of array
            int k = 0; // use in temp array
            int i = 0; //a var for while loop
            int j = 0;
            while (true)
            {
                if (command[i] == ']')
                {
                    fake[j] = command.substr(k, i - k);
                    break;
                }
                if (command[i] == ',')
                {
                    fake[j] = command.substr(k, i - k);
                    k = i + 1;
                    j++;
                }
                i++;
            }
            mat[num].arrs = new string *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arrs[i] = new string[column];
            }
            k = 0;
            for (size_t i = 0; i < row; i++)
            {
                for (size_t j = 0; j < column; j++)
                {
                    mat[num].arrs[i][j] = fake[k];
                    k++;
                }
            }
        }
        if (mat[num].typy == 3)
        {
            char num3;               //use for convert string to number
            char fake[row * column]; // temp array for store number of array
            int k = 0;               // use in temp array
            int i = 0;               //a var for while loop
            int j = 0;
            while (true)
            {
                if (command[i] == ']')
                {
                    num3 = command[i - 1];
                    fake[j] = num3;
                    break;
                }
                if (command[i] == ',')
                {
                    num3 = command[i - 1];
                    k = i + 1;
                    fake[j] = num3;
                    j++;
                }
                i++;
            }
            mat[num].arrc = new char *[column]; //make dynamically 2d array
            for (size_t i = 0; i < row; i++)
            {
                mat[num].arrc[i] = new char[column];
            }
            k = 0;
            for (size_t i = 0; i < row; i++)
            {
                for (size_t j = 0; j < column; j++)
                {
                    mat[num].arrc[i][j] = fake[k];
                    k++;
                }
            }
        }
        break;
    } //close bracket for case
    default:
        cout << "input argument for add matrix function is invalid!!!" << endl;
    } //close bracket for switch
    return 0;
} //close bracket for function
//end of add matrix function
/*******************************************************************/
/*******************************************************************/
//function for read the command
bool command(string command, struct store *a_mat)
{
    if (command.substr(0, 10) == "add matrix") // Check if a string contains a string
    {
        add_matrix(command, a_mat);
        num++;
        return true;
    }
    if (command.substr(0, 11) == "is_diagonal")
    {
        command = command.substr(12); //remove is_diagonal from command
        is_diagonal(command, a_mat);
        return true;
    }
    if (command.substr(0, 19) == "is_upper_triangular" || command.substr(0, 19) == "is_lower_triangular" || command.substr(0, 13) == "is_triangular")
    {
        is_triangular(command, a_mat);
        return true;
    }
    if (command.substr(0, 11) == "is_identity")
    {
        is_identity(command, a_mat);
        return true;
    }
    if (command.substr(0, 19) == "is_normal_symmetric" || command.substr(0, 17) == "is_skew_symmetric" || command.substr(0, 12) == "is_symmetric")
    {
        is_symmetrick(command, a_mat);
        return true;
    }
    if (command.substr(0, 7) == "inverse")
    {
        command = command.substr(8); //remove inversr from command
        inverse(command, a_mat);
        return true;
    }
    if (command.substr(0, 4) == "show")
    {
        show(command, a_mat);
        return true;
    }
    if (command.substr(0, 6) == "change")
    {
        change(command, a_mat);
        return true;
    }
    if (command.substr(0, 6) == "delete")
    {
        delete_matrix(command, a_mat);
        return true;
    }
    
    cout << "Error...input command is invalid!!" << endl;
    return false;
}
//end of command function
/*******************************************************************/
/*******************************************************************/
//is_diagonal function
bool is_diagonal(string command, struct store *mat)
{
    int check{-1};
    for (size_t i = 0; i <= num; i++)
    {
        if (mat[i].name == command)
        {
            check = i;
        }
    }
    if (check == -1)
    {
        cout << "Error...input name is invalid!!!" << endl;
        return false;
    }
    if (mat[check].row != mat[check].column)
    {
        cout << "The matrix isn't diagonal!!" << endl;
        return false;
    }
    int flag = 0;
    switch (mat[check].typy)
    {
    case 1: // int array
    {
        for (size_t i = 0; i < mat[check].row; i++)
        {
            for (size_t j = 0; j < mat[check].column; j++)
            {
                if (i != j)
                {
                    if (mat[check].arri[i][j] == 0)
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        cout << "The matrix isn't diagonal!!" << endl;
                        return false;
                    }
                }
            }
        }
        break;
    }
    case 2: // double array
    {
        for (size_t i = 0; i < mat[check].row; i++)
        {
            for (size_t j = 0; j < mat[check].column; j++)
            {
                if (i != j)
                {
                    if (mat[check].arrd[i][j] == (double)0)
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        cout << "The matrix isn't diagonal!!" << endl;
                        return false;
                    }
                }
            }
        }

        break;
    }
    case 3: //char array
    {
        for (size_t i = 0; i < mat[check].row; i++)
        {
            for (size_t j = 0; j < mat[check].column; j++)
            {
                if (i != j)
                {
                    if (mat[check].arrc[i][j] == 'z')
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        cout << "The matrix isn't diagonal!!" << endl;
                        return false;
                    }
                }
            }
        }
        break;
    }
    case 4: //string array
    {
        for (size_t i = 0; i < mat[check].row; i++)
        {
            for (size_t j = 0; j < mat[check].column; j++)
            {
                if (i != j)
                {
                    transform(mat[check].arrs[i][j].begin(), mat[check].arrs[i][j].end(), mat[check].arrs[i][j].begin(), //convert to lowercase
                              [](unsigned char c)
                              { return std::tolower(c); });
                    if (mat[check].arrs[i][j] == "zero")
                    {
                        flag = 1;
                    }
                    else
                    {
                        cout << "The matrix isn't diagonal!!" << endl;
                        return false;
                    }
                }
            }
        }
        break;
    }
    }
    if (flag == 1)
    {
        cout << "The matrix is diagonal!!" << endl;
    }
    return true;
}
//end of is_diagonal function
/*******************************************************************/
/*******************************************************************/
//is_triangular function
bool is_triangular(string command, struct store *mat)
{
    int pos = command.find(' ');
    string temp = command.substr(0, pos);
    command = command.substr(pos + 1);
    int check{-1};
    for (size_t i = 0; i <= num; i++)
    {
        if (mat[i].name == command)
        {
            check = i;
        }
    }
    if (check == -1)
    {
        cout << "Error...input name is invalid!!!" << endl;
        return false;
    }
    if (mat[check].row != mat[check].column)
    {
        cout << mat[check].name << " isn't triangular!!!" << endl;
        return false;
    }
    int c = 1;
    int flag = 0;
    int flag2 = 0;
    switch (mat[check].typy)
    {
    case 1: // int array
    {
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i > j)
                {
                    if (mat[check].arri[i][j] == 0)
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        c = 0;
                    }
                }
            }
        }
        c = 1;
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i < j)
                {
                    if (mat[check].arri[i][j] == 0)
                    {
                        flag2 = 1;
                    }
                    else
                    {
                        flag2 = 0;
                        c = 0;
                    }
                }
            }
        }
        break;
    }
    case 2: // double array
    {
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i > j)
                {
                    if (mat[check].arrd[i][j] == (double)0)
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        c = 0;
                    }
                }
            }
        }
        c = 1;
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i < j)
                {
                    if (mat[check].arrd[i][j] == (double)0)
                    {
                        flag2 = 1;
                    }
                    else
                    {
                        flag2 = 0;
                        c = 0;
                    }
                }
            }
        }
        break;
    }
    case 3: //char array
    {
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i > j)
                {
                    if (mat[check].arrc[i][j] == 'z')
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        c = 0;
                    }
                }
            }
        }
        c = 1;
        for (size_t i = 0; i < mat[check].row; i++)
        {
            for (size_t j = 0; j < mat[check].column; j++)
            {
                if (i < j)
                {
                    if (mat[check].arrc[i][j] == 'z')
                    {
                        flag2 = 1;
                    }
                    else
                    {
                        flag2 = 0;
                        c = 0;
                    }
                }
            }
        }
        break;
    }
    case 4: //string array
    {
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i > j)
                {
                    transform(mat[check].arrs[i][j].begin(), mat[check].arrs[i][j].end(), mat[check].arrs[i][j].begin(), //convert to lowercase
                              [](unsigned char c)
                              { return std::tolower(c); });
                    if (mat[check].arrs[i][j] == "zero")
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        c = 0;
                    }
                }
            }
        }
        c = 1;
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i < j)
                {
                    transform(mat[check].arrs[i][j].begin(), mat[check].arrs[i][j].end(), mat[check].arrs[i][j].begin(), //convert to lowercase
                              [](unsigned char c)
                              { return std::tolower(c); });
                    if (mat[check].arrs[i][j] == "zero")
                    {
                        flag2 = 1;
                    }
                    else
                    {
                        flag2 = 0;
                        c = 0;
                    }
                }
            }
        }

        break;
    }
    }
    if (temp == "is_upper_triangular" && flag2 == 1)
    {
        cout << mat[check].name << " is upper triangular" << endl;
        return true;
    }
    if (temp == "is_upper_triangular" && flag2 == 0)
    {
        cout << mat[check].name << " isn't upper triangular" << endl;
        return false;
    }
    if (temp == "is_lower_triangular" && flag == 1)
    {
        cout << mat[check].name << " is lower triangular" << endl;
        return true;
    }
    if (temp == "is_lower_triangular" && flag == 0)
    {
        cout << mat[check].name << " isn't lower triangular" << endl;
        return false;
    }

    if (temp == "is_triangular")
    {
        if (flag == 1 && flag2 == 1)
        {
            cout << mat[check].name << " is triangular" << endl;
            return true;
        }

        if (flag == 1)
        {
            cout << mat[check].name << " is lower triangular" << endl;
            return true;
        }
        if (flag2 == 1)
        {
            cout << mat[check].name << " is upper triangular" << endl;
            return true;
        }
    }
    cout << mat[check].name << " isn't triangular" << endl;
    return true;
}
//end of is_triangular function
/*******************************************************************/
/*******************************************************************/
//is_identity function
bool is_identity(string command, struct store *mat)
{
    string temp = command; //make a copy
    int pos = command.find(' ');
    command = command.substr(pos + 1);
    int check{-1};
    for (size_t i = 0; i < num; i++)
    {
        if (mat[i].name == command)
        {
            check = i;
        }
    }
    if (check == -1)
    {
        cout << "Error...input name is invalid!!!" << endl;
        return false;
    }
    if (mat[check].row != mat[check].column)
    {
        cout << mat[check].name << " isn't identity!!!" << endl;
        return false;
    }
    int flag = 0;
    switch (mat[check].typy)
    {
    case 1: // int array
    {
        for (size_t i = 0; i < mat[check].row; i++)
        {
            for (size_t j = 0; j < mat[check].column; j++)
            {
                if (i != j)
                {
                    if (mat[check].arri[i][j] == 0)
                    {
                    }
                    else
                    {
                        flag = 0;
                        cout << mat[check].name << " isn't identity!!!" << endl;
                        return false;
                    }
                }
                if (i == j)
                {
                    if (mat[check].arri[i][j] == 1)
                    {
                        flag = 1;
                    }
                    else
                    {
                        cout << mat[check].name << " isn't identity!!!" << endl;
                        return false;
                    }
                }
            }
        }
        break;
    }
    case 2: // double array
    {
        for (size_t i = 0; i < mat[check].row; i++)
        {
            for (size_t j = 0; j < mat[check].column; j++)
            {
                if (i != j)
                {
                    if (mat[check].arrd[i][j] == (double)0.0)
                    {
                    }
                    else
                    {
                        flag = 0;
                        cout << mat[check].name << " isn't identity!!!" << endl;
                        return false;
                    }
                }
                if (i == j)
                {
                    if (mat[check].arrd[i][j] == (double)1.0)
                    {
                        flag = 1;
                    }
                    else
                    {
                        cout << mat[check].name << " isn't identity!!!" << endl;
                        return false;
                    }
                }
            }
        }
        break;
    }
    case 3: //char array
    {
        for (size_t i = 0; i < mat[check].row; i++)
        {
            for (size_t j = 0; j < mat[check].column; j++)
            {
                if (i != j)
                {
                    if (mat[check].arrc[i][j] == 'z')
                    {
                    }
                    else
                    {
                        flag = 0;
                        cout << mat[check].name << " isn't identity!!!" << endl;
                        return false;
                    }
                }
                if (i == j)
                {
                    if (mat[check].arrc[i][j] == 'o')
                    {
                        flag = 1;
                    }
                    else
                    {
                        cout << mat[check].name << " isn't identity!!!" << endl;
                        return false;
                    }
                }
            }
        }
        break;
    }
    case 4: //string array
    {
        for (size_t i = 0; i < mat[check].row; i++)
        {
            for (size_t j = 0; j < mat[check].column; j++)
            {
                if (i != j)
                {
                    transform(mat[check].arrs[i][j].begin(), mat[check].arrs[i][j].end(), mat[check].arrs[i][j].begin(), //convert to lowercase
                              [](unsigned char c)
                              { return std::tolower(c); });
                    if (mat[check].arrs[i][j] == "zero")
                    {
                    }
                    else
                    {
                        flag = 0;
                        cout << mat[check].name << " isn't identity!!!" << endl;
                        return false;
                    }
                }
                if (i == j)
                {
                    transform(mat[check].arrs[i][j].begin(), mat[check].arrs[i][j].end(), mat[check].arrs[i][j].begin(), //convert to lowercase
                              [](unsigned char c)
                              { return std::tolower(c); });
                    if (mat[check].arrs[i][j] == "one")
                    {
                        flag = 1;
                    }
                    else
                    {
                        cout << mat[check].name << " isn't identity!!!" << endl;
                        return false;
                    }
                }
            }
        }
        break;
    }
    }
    if (flag == 1)
    {
        cout << mat[check].name << " is identity!!!" << endl;
    }
    return true;
}
//end of is_identity function
/*******************************************************************/
/*******************************************************************/
//is_symmetrick function
bool is_symmetrick(string command, struct store *mat)
{
    int pos = command.find(' ');
    string temp = command.substr(0, pos);
    command = command.substr(pos + 1);//seprate matrix name from command
    int check{-1};
    for (size_t i = 0; i <= num; i++)
    {
        if (mat[i].name == command)
        {
            check = i;
        }
    }
    if (check == -1)
    {
        cout << "Error...input name is invalid!!!" << endl;
        return false;
    }
    if (mat[check].row != mat[check].column)
    {
        cout << "The matrix isn't symmetric‬‬k!!!" << endl;
        return false;
    }
    int c = 1;//a extra condition for loop 
    int flag = 0;//use for normal symmetric
    int flag2 = 0;//use for skew symmetric
    switch (mat[check].typy)
    {
    case 1: // int array
    {
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i != j)
                {
                    if (mat[check].arri[i][j] == mat[check].arri[j][i])
                    {
                        flag = 1;
                    }
                    else
                    {
                        c = 0;
                        flag = 0;
                    }
                }
            }
        }
        c = 1;
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i != j)
                {
                    if (mat[check].arri[i][j] == (-1) * mat[check].arri[j][i])
                    {
                        flag2 = 1;
                    }
                    else
                    {
                        flag2 = 0;
                        c = 0;
                    }
                }
            }
        }

        break;
    }
    case 2: // double array
    {
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i != j)
                {
                    if (mat[check].arrd[i][j] == mat[check].arrd[j][i])
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        c = 0;
                    }
                }
            }
        }
        c = 1;
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i != j)
                {
                    if (mat[check].arrd[i][j] == (-1) * mat[check].arrd[j][i])
                    {
                        flag2 = 1;
                    }
                    else
                    {
                        flag2 = 0;
                        c = 0;
                    }
                }
            }
        }
        break;
    }
    case 3: //char array
    {
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i != j)
                {
                    if (mat[check].arrc[i][j] == mat[check].arrc[j][i])
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        c = 0;
                    }
                }
            }
        }
        c = 1;
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i != j)
                {
                    if ((int)mat[check].arrc[i][j] == (int)(-1) * mat[check].arrc[j][i])
                    {
                        flag2 = 1;
                    }
                    else
                    {
                        flag2 = 0;
                        c = 0;
                    }
                }
            }
        }
        break;
    }
    case 4: //string array
    {
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i != j)
                {
                    transform(mat[check].arrs[i][j].begin(), mat[check].arrs[i][j].end(), mat[check].arrs[i][j].begin(), //convert to lowercase
                              [](unsigned char c)
                              { return std::tolower(c); });
                    if (mat[check].arrs[i][j] == mat[check].arrs[j][i])
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        c = 0;
                    }
                }
            }
        }
        c = 1;
        for (size_t i = 0; i < mat[check].row && c == 1; i++)
        {
            for (size_t j = 0; j < mat[check].column && c == 1; j++)
            {
                if (i != j)
                {
                    reverse(mat[check].arrs[j][i].begin(), mat[check].arrs[j][i].end());
                    if (mat[check].arrs[j][i] == mat[check].arrs[i][j])
                    {
                        flag2 = 1;
                        reverse(mat[check].arrs[i][j].begin(), mat[check].arrs[i][j].end());
                    }
                    else
                    {
                        flag2 = 0;
                        c = 0;
                    }
                }
            }
        }
        break;
    }
    }
    if (temp == "is_normal_symmetric" && flag == 1)
    {
        cout << mat[check].name<< " is normal symmetric" << endl;
        return true;
    }
    if (temp == "is_normal_symmetric" && flag == 0)
    {
        cout << mat[check].name<< " isn't normal symmetric" << endl;
        return false;
    }
    if (temp == "is_skew_symmetric" && flag2 == 1)
    {
        cout<< mat[check].name << " is skew symmetric" << endl;
        return true;
    }
    if (temp == "is_skew_symmetric" && flag2 == 0)
    {
        cout<< mat[check].name << " isn't skew symmetric" << endl;
        return false;
    }
    if (temp == "is_symmetric")
    {
        if (flag == 1 && flag2 == 1)
        {
            cout << mat[check].name << " is normal symmetric(also skew symmetric)" << endl;
            return true;
        }
        if (flag == 1)
        {
            cout<< mat[check].name << " is normal symmetric" << endl;
            return true;
        }
        if (flag2 == 1)
        {
            cout<< mat[check].name << " is skew symmetric" << endl;
            return true;
        }
    }
    return true;
}
//end of is_symmetrick function
/*******************************************************************/
/*******************************************************************/
//inverse function
bool inverse(string command, struct store *mat)
{
    int check = 0;
    int i = 0;
    while (command[i] != '\0')
    {
        if (command[i] == ' ')
        {
            check = 1;// must add a new matrix
            break;
        }
        i++;
    }
    string temp;
    int flag = -1;
    if (check == 0)//inverse in matrix
    {
        for (size_t i = 0; i < num; i++)
        {
            if (mat[i].name == command)
            {
                flag = i;
            }
        }
        if (flag == -1)
        {
            cout << "Error...input name is invalid!!!" << endl;
            return false;
        }
        if (mat[flag].row != mat[flag].column)
        {
            cout << "The matrix couldn't be a inverse matrix!!!" << endl;
            return false;
        }
        switch (mat[flag].typy)
        {
        case 1:
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                for (size_t j = 0; j < mat[flag].column; j++)
                {
                    if (i != j)
                    {
                        mat[flag].arri[i][j] = mat[flag].arri[j][i];
                    }
                }
            }
            break;
        case 2:
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                for (size_t j = 0; j < mat[flag].column; j++)
                {
                    if (i != j)
                    {
                        mat[flag].arrd[i][j] = mat[flag].arrd[j][i];
                    }
                }
            }
            break;
        case 3:
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                for (size_t j = 0; j < mat[flag].column; j++)
                {
                    if (i != j)
                    {
                        mat[flag].arrc[i][j] = mat[flag].arrc[j][i];
                    }
                }
            }
            break;
        case 4:
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                for (size_t j = 0; j < mat[flag].column; j++)
                {
                    if (i != j)
                    {
                        mat[flag].arrs[i][j] = mat[flag].arrs[j][i];
                    }
                }
            }
            break;
        default:
            break;
        }

        return true;
    }
    if (check == 1)//add a new matrix
    {
        int pos = command.find(' ');
        temp = command.substr(0, pos);
        command = command.substr(pos + 1);
        for (size_t i = 0; i < num; i++)
        {
            if (mat[i].name == temp)
            {
                flag = i;
            }
        }
        if (flag == -1)
        {
            cout << "Error...input name is invalid!!!" << endl;
            return false;
        }
        if (mat[flag].row != mat[flag].column)
        {
            cout << "The matrix couldn't be a inverse matrix!!!" << endl;
            return false;
        }
        mat[num].name = command; // add matrix
        switch (mat[flag].typy)
        {
        case 1: //int array
        {
            mat[num].row = mat[flag].row;
            mat[num].column = mat[flag].column;
            mat[num].typy = mat[flag].typy;
            mat[num].arri = new int *[mat[flag].column]; //make dynamically 2d array
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                mat[num].arri[i] = new int[mat[flag].column];
            }
            //copy matrix
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                for (size_t j = 0; j < mat[flag].column; j++)
                {
                    mat[num].arri[i][j] = mat[flag].arri[i][j];
                }
            }
            //inverse
            int copy = 0;
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                for (size_t j = 0; j < mat[flag].column; j++)
                {
                    if (i > j)
                    {
                        copy = mat[num].arri[j][i];
                        mat[num].arri[j][i] = mat[num].arri[i][j];
                        mat[num].arri[i][j] = copy;
                    }
                }
            }
            num++;
            break;
        }
        case 2: //double array
        {
            //copy matrix
            mat[num].row = mat[flag].row;
            mat[num].column = mat[flag].column;
            mat[num].typy = mat[flag].typy;
            mat[num].arrd = new double *[mat[flag].column]; //make dynamically 2d array
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                mat[num].arrd[i] = new double[mat[flag].column];
            }
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                for (size_t j = 0; j < mat[flag].column; j++)
                {
                    mat[num].arrd[i][j] = mat[flag].arrd[i][j];
                }
            }
            //inverse
            double copy = 0;
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                for (size_t j = 0; j < mat[flag].column; j++)
                {
                    if (i > j)
                    {
                        copy = mat[num].arrd[j][i];
                        mat[num].arrd[j][i] = mat[num].arrd[i][j];
                        mat[num].arrd[i][j] = copy;
                    }
                }
            }
            num++;
            break;
        }
        case 3: //char array
        {
            //copy matrix
            mat[num].row = mat[flag].row;
            mat[num].column = mat[flag].column;
            mat[num].typy = mat[flag].typy;
            mat[num].arrc = new char *[mat[flag].column]; //make dynamically 2d array
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                mat[num].arrc[i] = new char[mat[flag].column];
            }
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                for (size_t j = 0; j < mat[flag].column; j++)
                {
                    mat[num].arrc[i][j] = mat[flag].arrc[i][j];
                }
            }
            //inverse
            char copy = ' ';
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                for (size_t j = 0; j < mat[flag].column; j++)
                {
                    if (1 > j)
                    {
                        copy = mat[num].arrc[j][i];
                        mat[num].arrc[j][i] = mat[num].arrc[i][j];
                        mat[num].arrc[i][j] = copy;
                    }
                }
            }
            num++;
            break;
        }
        case 4: //string array
        {
            //copy matrix
            mat[num].row = mat[flag].row;
            mat[num].column = mat[flag].column;
            mat[num].typy = mat[flag].typy;
            mat[num].arrs = new string *[mat[flag].column]; //make dynamically 2d array
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                mat[num].arrs[i] = new string[mat[flag].column];
            }
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                for (size_t j = 0; j < mat[flag].column; j++)
                {
                    mat[num].arrs[i][j] = mat[flag].arrs[i][j];
                }
            }
            //inverse
            string copy = " ";
            for (size_t i = 0; i < mat[flag].row; i++)
            {
                for (size_t j = 0; j < mat[flag].column; j++)
                {
                    if (i > j)
                    {
                        copy = mat[num].arrs[j][i];
                        mat[num].arrs[j][i] = mat[num].arrs[i][j];
                        mat[num].arrs[i][j] = copy;
                    }
                }
            }
            num++;
            break;
        }
        default:
            break;
        }
        return true;
    }
    cout << "Error...input command for *inverse function* is invalid!!!!" << endl;
    return false;
}
//end of inverse function
/*******************************************************************/
/*******************************************************************/
//show function
bool show(string command, struct store *mat)
{
    command = command.substr(5);
    int check = -1;
    for (size_t i = 0; i < num; i++)
    {
        if (mat[i].name == command)
        {
            check = i;
        }
    }
    if (check == -1)
    {
        cout << "Error...input name is invalid!!!" << endl;
        return false;
    }

    switch (mat[check].typy)
    {
    case 1: //int array
        cout << mat[check].name << ": " << endl;
        for (size_t i = 0; i < mat[check].row; i++)
        {
            for (size_t j = 0; j < mat[check].column; j++)
            {
                cout << mat[check].arri[i][j] << "   ";
            }
            cout << endl;
        }
        break;
    case 2: //double array
        cout << mat[check].name << ": " << endl;
        for (size_t i = 0; i < mat[check].row; i++)
        {
            for (size_t j = 0; j < mat[check].column; j++)
            {
                cout << mat[check].arrd[i][j] << "   ";
            }
            cout << endl;
        }
        break;
    case 3: //char array
        cout << mat[check].name << ": " << endl;
        for (size_t i = 0; i < mat[check].row; i++)
        {
            for (size_t j = 0; j < mat[check].column; j++)
            {
                cout << mat[check].arrc[i][j] << "   ";
            }
            cout << endl;
        }
        break;
    case 4: //string array
        cout << mat[check].name << ": " << endl;
        for (size_t i = 0; i < mat[check].row; i++)
        {
            for (size_t j = 0; j < mat[check].column; j++)
            {
                cout << mat[check].arrs[i][j] << "   ";
            }
            cout << endl;
        }
        break;
    default:
        break;
    }
    return true;
}
//end of show function
/*******************************************************************/
/*******************************************************************/
//delete function
bool delete_matrix(string command, struct store *mat)
{
    command = command.substr(7);
    int check = -1;
    for (size_t i = 0; i < num; i++)
    {
        if (mat[i].name == command)
        {
            check = i;
        }
    }
    if (check == -1)
    {
        cout << "Error...input name is invalid!!!" << endl;
        return false;
    }
    for (size_t i = check; i < num; i++)
    {
        mat[i] = mat[i + 1];
    }
    cout << "delete"
         << " successfully!!!" << endl;
    return true;
}
//end of delete function
/*******************************************************************/
/*******************************************************************/
//change function
bool change(string command, struct store *mat)
{
    command = command.substr(7); //remove change
    int pos = command.find(' ');
    string temp = command.substr(0, pos);
    int check{-1};
    for (size_t i = 0; i < num; i++)
    {
        if (mat[i].name == temp)
        {
            check = i;
        }
    }

    if (check == -1)
    {
        cout << "Error...input name is invalid!!!" << endl;
        return false;
    }
    command = command.substr(pos + 1);
    switch (mat[check].typy)
    {
    case 1: //int array
    {
        int i = 0; //use for command
        int arr[3] = {0};
        int k = 0; //use for arr
        bool ch = true;

        while (check)
        {
            if (isdigit(command[i]))
            {
                arr[k] = arr[k] * 10 + (command[i] - 48); // convert string to number
            }
            if (command[i] == ' ')
            {
                k++;
            }
            if (command[i] == '\0')
            {

                ch = false;
            }
            i++;
        }
        int row = arr[0];
        int column = arr[1];
        int new_num = arr[2];
        mat[check].arri[row - 1][column - 1] = new_num;
        break;
    }
    case 2: //double array
    {
        int i = 0; //use for command
        int arr[2] = {0};
        int k = 0; //use for arr
        string temp;
        bool ch = true;
        while (ch)
        {
            if (isdigit(command[i]))
            {
                arr[k] = arr[k] * 10 + (command[i] - 48); // convert string to number
            }
            if (command[i] == ' ')
            {
                k++;
            }
            if (k == 2)
            {
                temp = command.substr(i + 1);
                ch = false;
            }
            i++;
        }
        int row = arr[0];
        int column = arr[1];
        double new_num = stod(temp);
        mat[check].arrd[row - 1][column - 1] = new_num;
        break;
    }
    case 3: //char array
    {
        int i = 0; //use for command
        int arr[2] = {0};
        int k = 0; //use for arr
        char new_char;
        bool ch = true;
        while (ch)
        {
            if (isdigit(command[i]))
            {
                arr[k] = arr[k] * 10 + (command[i] - 48); // convert string to number
            }
            if (command[i] == ' ')
            {
                k++;
            }
            if (k == 2)
            {
                new_char = command[i + 1];
                ch = false;
            }

            i++;
        }

        int row = arr[0];
        int column = arr[1];
        mat[check].arrc[row - 1][column - 1] = new_char;
        break;
    }
    case 4: //string array
    {
        int i = 0; //use for command
        int arr[2] = {0};
        int k = 0; //use for arr
        string temp;
        bool ch = true;
        while (ch)
        {
            if (isdigit(command[i]))
            {
                arr[k] = arr[k] * 10 + (command[i] - 48); // convert string to number
            }
            if (command[i] == ' ')
            {
                k++;
            }
            if (k == 2)
            {
                temp = command.substr(i + 1);
                ch = false;
            }

            i++;
        }
        int row = arr[0];
        int column = arr[1];
        mat[check].arrs[row - 1][column - 1] = temp;
        break;
    }
    default:
        break;
    }
    return true;
}
//end of inverse function
/*******************************************************************/
/*******************************************************************/
//exit function
bool exit(struct store *mat)
{
    for (size_t i = 0; i < num; i++)
    {
        switch (mat[i].typy)
        {
        case 1:
            for (size_t i = 0; i < mat[i].row; i++)
            {
                delete[] mat[i].arri[i];
            }
            delete[] mat[i].arri;
            break;
        case 2:
            for (size_t i = 0; i < mat[i].row; i++)
            {
                delete[] mat[num].arrd[i];
            }
            delete[] mat[num].arrd;
        case 3:
            for (size_t i = 0; i < mat[i].row; i++)
            {
                delete[] mat[num].arrc[i];
            }
            delete[] mat[num].arrc;
        case 4:
            for (size_t i = 0; i < mat[i].row; i++)
            {
                delete[] mat[num].arrs[i];
            }
            delete[] mat[num].arrs;
        default:
            break;
        }
    }
    return true;
}
//end of exit function