#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include "function.h"
using namespace std;
//global var for dynamic memory
// int num = 0;
// //function prototype
// void message();
// void command(string command, struct store *mat);
// bool is_diagonal(string command, struct store *mat);
// bool is_triangular(string command, struct store *mat);
// bool is_identity‬‬(string command, struct store *mat);
// bool is_symmetric‬‬k(string command, struct store *mat);
// bool inverse(string command, struct store *mat);
// bool show(string command, struct store *mat);
// bool delete_matrix(string command, struct store *mat);
// bool change(string command, struct store *mat);
// int tyid(string command);

// struct store
// {
//     string command;
//     string name;
//     int row;
//     int column;
//     int check; //identity data type in add matrix function
//     int **arri;
//     double **arrd;
//     char **arrc;
//     string **arrs;
// };

// int add_matrix(string command, struct store *mat)
// {
//     int pos = 0;
//     int row = 0; //row of array
//     for (pos = 0; isdigit(command[pos]); pos++)
//     {
//         row = row * 10 + (command[pos] - 48); // convert string to number
//     }
//     int pos1 = pos; //make a copy for use in switch case
//     int check = 0;
//     cout << "row :" << row << endl;
//     while (command[pos] != '\0')
//     {
//         if (isdigit(command[pos]))
//         {
//             check = 1; //add matrix first 3 4
//         }
//         if (command[pos] == '[')
//         {
//             if (check == 1)
//             {
//                 check = 3; //add matrix first 3 4 [...]
//                 break;
//             }
//             else
//             {
//                 check = 2; //add matrix first 3 [...]
//                 break;
//             }
//         }
//         pos++;
//     }
//     int column = 0; //column of array
//     switch (check)
//     {
//     case 0:
//     {
//         column = row;
//         mat[num].row = row;
//         mat[num].column = column;
//         cout << "Enter a number for"
//              << " row: " << 1 << " column: " << 1 << " ---> ";
//         string temp; //use recognize datatype of array
//         cin >> temp;
//         mat[num].check = tyid(temp);
//         if (mat[num].check == 1)
//         {
//             cout << "in int if " << endl;
//             int first = stoi(temp);
//             mat[num].arri = new int *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arri[i] = new int[column];
//             }
//             mat[num].arri[0][0] = first;
//             int j = 0;
//             for (size_t i = 0; i < row; i++) // fill array. input by user
//             {
//                 if (i == 0)
//                 {
//                     j = 1;
//                 }
//                 else
//                 {
//                     j = 0;
//                 }
//                 for (; j < column; j++)
//                 {
//                     cout << "Enter a number for"
//                          << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
//                     cin >> mat[num].arri[i][j];
//                 }
//             }
//         }
//         cout << mat[num].check << endl;
//         if (mat[num].check == 2)
//         {
//             double first = stod(temp);
//             cout << "in d if" << endl;
//             mat[num].arrd = new double *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arrd[i] = new double[column];
//             }
//             mat[num].arrd[0][0] = first;
//             int j = 0;
//             for (size_t i = 0; i < row; i++) // fill array. input by user
//             {
//                 if (i == 0)
//                 {
//                     j = 1;
//                 }
//                 else
//                 {
//                     j = 0;
//                 }
//                 for (j; j < column; j++)
//                 {
//                     cout << "Enter a number for"
//                          << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
//                     cin >> mat[num].arrd[i][j];
//                 }
//             }
//         }
//         if (mat[num].check == 3)
//         {
//             cout << "in char if" << endl;
//             mat[num].arrc = new char *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arrc[i] = new char[column];
//             }
//             mat[num].arrc[0][0] = temp[0];
//             int j = 0;
//             for (size_t i = 0; i < row; i++) // fill array. input by user
//             {
//                 if (i == 0)
//                 {
//                     j = 1;
//                 }
//                 else
//                 {
//                     j = 0;
//                 }
//                 for (j; j < column; j++)
//                 {
//                     cout << "Enter a number for"
//                          << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
//                     cin >> mat[num].arrc[i][j];
//                 }
//             }
//         }
//         if (mat[num].check == 4)
//         {
//             cout << "in string if" << endl;
//             mat[num].arrs = new string *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arrs[i] = new string[column];
//             }
//             int j = 0;
//             mat[num].arrs[0][0] = temp;
//             j++;
//             for (size_t i = 0; i < row; i++) // fill array. input by user
//             {
//                 if (i == 0)
//                 {
//                     j = 1;
//                 }
//                 else
//                 {
//                     j = 0;
//                 }
//                 for (j; j < column; j++)
//                 {
//                     cout << "Enter a number for"
//                          << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
//                     cin >> mat[num].arrs[i][j];
//                 }
//             }
//         }
//         break;
//     }
//     case 1:
//     {
//         command = command.substr(pos1 + 1);
//         for (pos1 = 0; isdigit(command[pos1]); pos1++)
//         {
//             column = column * 10 + (int(command[pos1] - 48)); // convert string to number
//         }
//         mat[num].row = row;
//         mat[num].column = column;
//         cout << "Enter a number for"
//              << " row: " << 0 << " column: " << 0 << " ---> ";
//         string temp; //use recognize datatype of array
//         cin >> temp;
//         mat[num].check = tyid(temp);
//         if (mat[num].check == 1)
//         {
//             cout << "in int if " << endl;
//             int first = stoi(temp);
//             mat[num].arri = new int *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arri[i] = new int[column];
//             }
//             mat[num].arri[0][0] = first;
//             int j = 0;
//             for (size_t i = 0; i < row; i++) // fill array. input by user
//             {
//                 if (i == 0)
//                 {
//                     j = 1;
//                 }
//                 else
//                 {
//                     j = 0;
//                 }
//                 for (; j < column; j++)
//                 {
//                     cout << "Enter a number for"
//                          << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
//                     cin >> mat[num].arri[i][j];
//                 }
//             }
//         }
//         if (mat[num].check == 2)
//         {
//             double first = stod(temp);
//             cout << "in d if" << endl;
//             mat[num].arrd = new double *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arrd[i] = new double[column];
//             }
//             mat[num].arrd[0][0] = first;
//             int j = 0;
//             for (size_t i = 0; i < row; i++) // fill array. input by user
//             {
//                 if (i == 0)
//                 {
//                     j = 1;
//                 }
//                 else
//                 {
//                     j = 0;
//                 }
//                 for (j; j < column; j++)
//                 {
//                     cout << "Enter a number for"
//                          << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
//                     cin >> mat[num].arrd[i][j];
//                 }
//             }
//         }
//         if (mat[num].check == 3)
//         {
//             cout << "in char if" << endl;
//             mat[num].arrc = new char *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arrc[i] = new char[column];
//             }
//             mat[num].arrc[0][0] = temp[0];
//             int j = 0;
//             for (size_t i = 0; i < row; i++) // fill array. input by user
//             {
//                 if (i == 0)
//                 {
//                     j = 1;
//                 }
//                 else
//                 {
//                     j = 0;
//                 }
//                 for (j; j < column; j++)
//                 {
//                     cout << "Enter a number for"
//                          << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
//                     cin >> mat[num].arrc[i][j];
//                 }
//             }
//         }
//         if (mat[num].check == 4)
//         {
//             cout << "in string if" << endl;
//             mat[num].arrs = new string *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arrs[i] = new string[column];
//             }
//             int j = 0;
//             mat[num].arrs[0][0] = temp;
//             j++;
//             for (size_t i = 0; i < row; i++) // fill array. input by user
//             {
//                 if (i == 0)
//                 {
//                     j = 1;
//                 }
//                 else
//                 {
//                     j = 0;
//                 }
//                 for (j; j < column; j++)
//                 {
//                     cout << "Enter a number for"
//                          << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
//                     cin >> mat[num].arrs[i][j];
//                 }
//             }
//         }
//         break;
//     }
//     case 2:
//     {
//         column = row;
//         mat[num].row = row;
//         mat[num].column = column;
//         command = command.substr(pos1 + 2);
//         int pos2 = command.find(',');
//         string temp = command.substr(0, pos2);
//         mat[num].check = tyid(temp);
//         if (mat[num].check == 1)
//         {
//             int num3 = 0;           //use for convert string to number
//             int fake[row * column]; // temp array for store number of array
//             cout << command << endl;
//             int k = 0; // use in temp array
//             int i = 0; //a var for while loop
//             while (command[i] != ']')
//             {
//                 if (isdigit(command[i]))
//                 {
//                     num3 = num3 * 10 + (int(command[i] - 48));
//                 }
//                 else
//                 {
//                     fake[k] = num3;
//                     num3 = 0;
//                     k++;
//                 }
//                 i++;
//             }
//             fake[k] = num3;                    // initialize last number of string
//             mat[num].arri = new int *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arri[i] = new int[column];
//             }
//             k = 0;
//             for (size_t i = 0; i < row; i++)
//             {
//                 for (size_t j = 0; j < column; j++)
//                 {
//                     mat[num].arri[i][j] = fake[k];
//                     k++;
//                 }
//             }
//         }
//         if (mat[num].check == 2)
//         {
//             string num3;               //use for convert string to number
//             double num_double = 0;     //use for convert string to number
//             double fake[row * column]; // temp array for store number of array
//             cout << command << endl;
//             int k = 0; // use in temp array
//             int i = 0; //a var for while loop
//             int j = 0; //use for fake array
//             while (true)
//             {
//                 if (command[i] == ']')
//                 {
//                     num3 = command.substr(k, i);
//                     fake[j] = stod(num3);
//                     break;
//                 }

//                 if (command[i] == ',')
//                 {
//                     num3 = command.substr(k, i);
//                     k = i + 1;
//                     fake[j] = stod(num3);
//                     j++;
//                 }
//                 i++;
//             }
//             mat[num].arrd = new double *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arrd[i] = new double[column];
//             }
//             k = 0;
//             for (size_t i = 0; i < row; i++)
//             {
//                 for (size_t j = 0; j < column; j++)
//                 {
//                     mat[num].arrd[i][j] = fake[k];
//                     k++;
//                 }
//             }
//         }

//         if (mat[num].check == 4)
//         {
//             string num3;               //use for convert string to number
//             string fake[row * column]; // temp array for store number of array
//             cout << command << endl;
//             int k = 0; // use in temp array
//             int i = 0; //a var for while loop
//             int j = 0;
//             while (true)
//             {
//                 if (command[i] == ']')
//                 {
//                     num3 = command.substr(k, i);
//                     fake[j] = num3;
//                     break;
//                 }
//                 if (command[i] == ',')
//                 {
//                     num3 = command.substr(k, i);
//                     k = i + 1;
//                     fake[j] = num3;
//                     j++;
//                 }
//                 i++;
//             }
//             mat[num].arrs = new string *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arrs[i] = new string[column];
//             }
//             k = 0;
//             for (size_t i = 0; i < row; i++)
//             {
//                 for (size_t j = 0; j < column; j++)
//                 {
//                     mat[num].arrs[i][j] = fake[k];
//                     k++;
//                 }
//             }
//         }
//         if (mat[num].check == 3)
//         {
//             char num3;               //use for convert string to number
//             char fake[row * column]; // temp array for store number of array
//             cout << command << endl;
//             int k = 0; // use in temp array
//             int i = 0; //a var for while loop
//             int j = 0;
//             while (true)
//             {
//                 if (command[i] == ']')
//                 {
//                     num3 = command[i - 1];
//                     fake[j] = num3;
//                     break;
//                 }
//                 if (command[i] == ',')
//                 {
//                     num3 = command[i - 1];
//                     k = i + 1;
//                     fake[j] = num3;
//                     j++;
//                 }
//                 i++;
//             }
//             mat[num].arrc = new char *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arrc[i] = new char[column];
//             }
//             k = 0;
//             for (size_t i = 0; i < row; i++)
//             {
//                 for (size_t j = 0; j < column; j++)
//                 {
//                     mat[num].arrc[i][j] = fake[k];
//                     k++;
//                 }
//             }
//         }
//         break;
//     }
//     case 3:
//     {
//         command = command.substr(pos1 + 1);
//         for (size_t i = 0; i < isdigit(command[i]); i++)
//         {
//             column = column * 10 + (int(command[i] - 48)); // convert string to number
//         }
//         mat[num].row = row;
//         mat[num].column = column;
//         int pos2 = command.find(',');
//         string temp = command.substr(0, pos2);
//         mat[num].check = tyid(temp);

//         if (mat[num].check == 1)
//         {
//             int num3 = 0;           //use for convert string to number
//             int fake[row * column]; // temp array for store number of array
//             cout << command << endl;
//             int k = 0; // use in temp array
//             int i = 0; //a var for while loop
//             while (command[i] != ']')
//             {
//                 if (isdigit(command[i]))
//                 {
//                     num3 = num3 * 10 + (int(command[i] - 48));
//                 }
//                 else
//                 {
//                     fake[k] = num3;
//                     num3 = 0;
//                     k++;
//                 }
//                 i++;
//             }
//             fake[k] = num3;                    // initialize last number of string
//             mat[num].arri = new int *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arri[i] = new int[column];
//             }
//             k = 0;
//             for (size_t i = 0; i < row; i++)
//             {
//                 for (size_t j = 0; j < column; j++)
//                 {
//                     mat[num].arri[i][j] = fake[k];
//                     k++;
//                 }
//             }
//         }
//         if (mat[num].check == 2)
//         {
//             string num3;               //use for convert string to number
//             double fake[row * column]; // temp array for store number of array
//             int k = 0;                 // use in temp array
//             int i = 0;                 //a var for while loop
//             int j = 0;
//             while (true)
//             {
//                 if (command[i] == ']')
//                 {
//                     num3 = command.substr(k, i);
//                     fake[j] = stod(num3);
//                     break;
//                 }

//                 if (command[i] == ',')
//                 {
//                     num3 = command.substr(k, i);
//                     k = i + 1;
//                     fake[j] = stod(num3);
//                     j++;
//                 }
//                 i++;
//             }
//             mat[num].arrd = new double *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arrd[i] = new double[column];
//             }
//             k = 0;
//             for (size_t i = 0; i < row; i++)
//             {
//                 for (size_t j = 0; j < column; j++)
//                 {
//                     mat[num].arrd[i][j] = fake[k];
//                     k++;
//                 }
//             }
//         }

//         if (mat[num].check == 4)
//         {
//             string num3;               //use for convert string to number
//             string fake[row * column]; // temp array for store number of array
//             cout << command << endl;
//             int k = 0; // use in temp array
//             int i = 0; //a var for while loop
//             int j = 0;
//             while (true)
//             {
//                 if (command[i] == ']')
//                 {
//                     num3 = command.substr(k, i);
//                     fake[j] = num3;
//                     break;
//                 }
//                 if (command[i] == ',')
//                 {
//                     num3 = command.substr(k, i);
//                     k = i + 1;
//                     fake[j] = num3;
//                     j++;
//                 }
//                 i++;
//             }
//             mat[num].arrs = new string *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arrs[i] = new string[column];
//             }
//             k = 0;
//             for (size_t i = 0; i < row; i++)
//             {
//                 for (size_t j = 0; j < column; j++)
//                 {
//                     mat[num].arrs[i][j] = fake[k];
//                     k++;
//                 }
//             }
//         }
//         if (mat[num].check == 3)
//         {
//             char num3;               //use for convert string to number
//             char fake[row * column]; // temp array for store number of array
//             int k = 0;               // use in temp array
//             int i = 0;               //a var for while loop
//             int j = 0;
//             while (true)
//             {
//                 if (command[i] == ']')
//                 {
//                     num3 = command[i - 1];
//                     fake[j] = num3;
//                     break;
//                 }
//                 if (command[i] == ',')
//                 {
//                     num3 = command[i - 1];
//                     k = i + 1;
//                     fake[j] = num3;
//                     j++;
//                 }
//                 i++;
//             }
//             mat[num].arrc = new char *[column]; //make dynamically 2d array
//             for (size_t i = 0; i < row; i++)
//             {
//                 mat[num].arrc[i] = new char[column];
//             }
//             k = 0;
//             for (size_t i = 0; i < row; i++)
//             {
//                 for (size_t j = 0; j < column; j++)
//                 {
//                     mat[num].arrc[i][j] = fake[k];
//                     k++;
//                 }
//             }
//         }
//         break;
//     } //close bracket for case
//     } //close bracket for switch
// } //close bracket for function

//void display(struct store *mat);

//struct for store 2d array and name of array

int main()
{
    string request;
    message();
    getline(cin, request);
    transform(request.begin(), request.end(), request.begin(), //convert to lowercase
              [](unsigned char c)
              { return std::tolower(c); });

    store *matrix = new store[100];
    //request != "exit"
    while (request != "exit")
    {
        command(request, matrix);
        cin.ignore();
        request = "";
        message();
        getline(cin, request);
        transform(request.begin(), request.end(), request.begin(), //convert to lowercase
                  [](unsigned char c)
                  { return std::tolower(c); });
    }
    return 0;
}

//function for show message(abilities of program)
// void message()
// {
//     cout << "********************" << endl;
//     cout << "what do you want?" << endl;
//     cout << "----------------------" << endl;
//     cout << "add matrix" << endl;
//     cout << "----------------------" << endl;
//     cout << "is_diagonal‬‬" << endl;
//     cout << "----------------------" << endl;
//     cout << "is_upper_triangular‬‬" << endl;
//     cout << "----------------------" << endl;
//     cout << "is_lower_triangular‬‬" << endl;
//     cout << "----------------------" << endl;
//     cout << "is_triangular‬‬" << endl;
//     cout << "----------------------" << endl;
//     cout << "is_identity‬‬" << endl;
//     cout << "----------------------" << endl;
//     cout << "is_normal_symmetric‬‬" << endl;
//     cout << "----------------------" << endl;
//     cout << "is_skew_symmetric‬‬" << endl;
//     cout << "----------------------" << endl;
//     cout << "is_symmetric‬‬k" << endl;
//     cout << "----------------------" << endl;
//     cout << "‫‪inverse‬‬" << endl;
//     cout << "----------------------" << endl;
//     cout << "show" << endl;
//     cout << "----------------------" << endl;
//     cout << "delete" << endl;
//     cout << "----------------------" << endl;
//     cout << "exit" << endl;
//     cout << "********************" << endl;
// }
// //end of massage function

// //function for read the command
// void command(string command, struct store *a_mat)
// {

//     if (command.substr(0, 10) == "add matrix") // Check if a string contains a string
//     {
//         command = command.substr(11); //remove add matrix from command
//         int pos1 = command.find(' ');
//         a_mat[num].name = command.substr(0, pos1); // store array names
//         command = command.substr(pos1 + 1);        //remove name from command
//         add_matrix(command, a_mat);
//         //display(a_mat);
//         num++;
//     }
//     if (command.substr(0, 11) == "is_diagonal‬‬")
//     {
//         command = command.substr(12); //remove is_diagonal from command
//         is_diagonal(command, a_mat);
//     }
//     if (command.substr(0, 19) == "is_upper_triangular" || command.substr(0, 19) == "is_lower_triangular‬‬" || command.substr(0, 13) == "is_identity‬‬")
//     {
//         is_triangular(command, a_mat);
//     }
//     if (command.substr(0, 11) == "identity‬‬")
//     {
//         is_identity‬‬(command, a_mat);
//     }
//     if (command.substr(0, 19) == "is_normal_symmetric‬‬" || command.substr(0, 17) == "is_skew_symmetric" || command.substr(0, 13) == "is_symmetric‬‬k")
//     {
//         is_symmetric‬‬k(command, a_mat);
//     }
//     if (command.substr(0, 7) == "inverse")
//     {
//         command = command.substr(8); //remove inversr from command
//         inverse(command, a_mat);
//     }
//     if (command.substr(0, 4) == "show")
//     {
//         show(command, a_mat);
//     }
//     if (command.substr(0, 6) == "delete")
//     {
//         delete_matrix(command, a_mat);
//     }
// }
// int tyid(string command)
// {
//     int check;
//     if (isdigit(command[0]))
//     {
//         if (command.find('.'))
//         {
//             check = 2;//double
//         }
//         else
//         {
//             check = 1;//int
//         }
//     }
//     if (!isdigit(command[0]))
//     {
//         if (command.length() > 1)
//         {
//             check = 4;//string
//         }
//         if (command.length() == 1)
//         {
//             check = 3;//char
//         }

//     }
//     return check;
// }

// //is_diagonal function
// bool is_diagonal(string command, struct store *mat)
// {
//     int check{-1};
//     for (size_t i = 0; i <= num; i++)
//     {
//         if (mat[i].name == command)
//         {
//             check = i;
//         }
//     }
//     if (check == -1)
//     {
//         cout << "Error...input name is invalid!!!" << endl;
//         return false;
//     }
//     if (mat[check].row != mat[check].column)
//     {
//         cout << "The matrix isn't diagonal!!" << endl;
//         return false;
//     }
//     int flag = 0;
//     switch (mat[check].check)
//     {
//     case 1: // int array
//     {
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i != j)
//                 {
//                     if (mat[check].arri[i][j] == 0)
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         flag = 0;
//                         cout << "The matrix isn't diagonal!!" << endl;
//                         return false;
//                     }
//                 }
//             }
//         }
//         break;
//     }
//     case 2: // double array
//     {
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i != j)
//                 {
//                     if (mat[check].arrd[i][j] == (double)0)
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         flag = 0;
//                         cout << "The matrix isn't diagonal!!" << endl;
//                         return false;
//                     }
//                 }
//             }
//         }

//         break;
//     }
//     case 3: //char array
//     {
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i != j)
//                 {
//                     if (mat[check].arrc[i][j] == 'z')
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         flag = 0;
//                         cout << "The matrix isn't diagonal!!" << endl;
//                         return false;
//                     }
//                 }
//             }
//         }
//         break;
//     }
//     case 4: //string array
//     {
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i != j)
//                 {
//                     transform(mat[check].arrs[i][j].begin(), mat[check].arrs[i][j].end(), mat[check].arrs[i][j].begin(), //convert to lowercase
//                               [](unsigned char c)
//                               { return std::tolower(c); });
//                     if (mat[check].arrs[i][j] == "zero")
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         cout << "The matrix isn't diagonal!!" << endl;
//                         return false;
//                     }
//                 }
//             }
//         }
//         break;
//     }
//     }
//     if (flag == 1)
//     {
//         cout << "The matrix is diagonal!!" << endl;
//         return true;
//     }
// }
// //end of is_diagonal function

// //is_triangular function
// bool is_triangular(string command, struct store *mat)
// {
//     string temp = command; //make a copy
//     int pos = command.find(' ');
//     command = command.substr(pos + 1);
//     int check{-1};
//     for (size_t i = 0; i <= num; i++)
//     {
//         if (mat[i].name == command)
//         {
//             check = i;
//         }
//     }
//     if (check == -1)
//     {
//         cout << "Error...input name is invalid!!!" << endl;
//         return false;
//     }
//     if (mat[check].row != mat[check].column)
//     {
//         cout << "The matrix isn't triangular!!!" << endl;
//         return false;
//     }
//     int flag = 0;
//     switch (mat[check].check)
//     {
//     case 1: // int array
//     {
//         int flag = 0;
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i > j)
//                 {
//                     if (mat[check].arri[i][j] == 0)
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         flag = 0;
//                     }
//                 }
//                 if (i < j)
//                 {
//                     if (mat[check].arri[i][j] == 0)
//                     {
//                         flag = 2;
//                     }
//                 }
//             }
//         }
//         break;
//     }
//     case 2: // double array
//     {
//         int flag = 0;
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i > j)
//                 {
//                     if (mat[check].arrd[i][j] == (double)0)
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         flag = 0;
//                     }
//                 }
//                 if (i < j)
//                 {
//                     if (mat[check].arrd[i][j] == (double)0)
//                     {
//                         flag = 2;
//                     }
//                 }
//             }
//         }
//         break;
//     }
//     case 3: //char array
//     {
//         int flag = 0;
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i > j)
//                 {
//                     if (mat[check].arrc[i][j] == 'z')
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         flag = 0;
//                     }
//                 }
//                 if (i < j)
//                 {
//                     if (mat[check].arrc[i][j] == 'z')
//                     {
//                         flag = 2;
//                     }
//                 }
//             }
//         }
//         break;
//     }
//     case 4: //string array
//     {
//         int flag = 0;
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i > j)
//                 {
//                     transform(mat[check].arrs[i][j].begin(), mat[check].arrs[i][j].end(), mat[check].arrs[i][j].begin(), //convert to lowercase
//                               [](unsigned char c)
//                               { return std::tolower(c); });
//                     if (mat[check].arrs[i][j] == "zero")
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         flag = 0;
//                     }
//                 }
//                 if (i < j)
//                 {
//                     if (mat[check].arrs[i][j] == "zero")
//                     {
//                         flag = 2;
//                     }
//                 }
//             }
//         }
//         break;
//     }
//     }
//     if (flag == 0)
//     {
//         cout << "the matrix isn't triangular" << endl;
//     }
//     if (temp == "is_upper_triangular" && flag == 2)
//     {
//         cout << "The matrix is lower triangular" << endl;
//     }
//     if (temp == "is_lower_triangular" && flag == 1)
//     {
//         cout << "The matrix is upper triangular" << endl;
//     }
//     if ((temp == "is_triangular") && (flag == 2 || flag == 1))
//     {
//         cout << "is_triangular" << endl;
//     }
//     return true;
// }
// //end of is_triangular function

// //is_identity function
// bool is_identity‬‬(string command, struct store *mat)
// {
//     string temp = command; //make a copy
//     int pos = command.find(' ');
//     command = command.substr(pos + 1);
//     int check{-1};
//     for (size_t i = 0; i <= num; i++)
//     {
//         if (mat[i].name == command)
//         {
//             check = i;
//         }
//     }
//     if (check == -1)
//     {
//         cout << "Error...input name is invalid!!!" << endl;
//         return false;
//     }
//     if (mat[check].row != mat[check].column)
//     {
//         cout << "The matrix isn't identity!!!" << endl;
//         return false;
//     }
//     int flag = 0;
//     switch (mat[check].check)
//     {
//     case 1: // int array
//     {
//         int flag = 0;
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i != j)
//                 {
//                     if (mat[check].arri[i][j] == 0)
//                     {
//                     }
//                     else
//                     {
//                         flag = 0;
//                         cout << "The matrix isn't identity!!!" << endl;
//                         return false;
//                     }
//                 }
//                 if (i == j)
//                 {
//                     if (mat[check].arri[i][j] == 1)
//                     {
//                         flag = 1;
//                     }
//                 }
//                 else
//                 {
//                     cout << "The matrix isn't identity!!!" << endl;
//                     return false;
//                 }
//             }
//         }
//         break;
//     }
//     case 2: // double array
//     {
//         int flag = 0;
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i != j)
//                 {
//                     if (mat[check].arrd[i][j] == (double)0.0)
//                     {
//                     }
//                     else
//                     {
//                         flag = 0;
//                         cout << "The matrix isn't identity!!!" << endl;
//                         return false;
//                     }
//                 }
//                 if (i == j)
//                 {
//                     if (mat[check].arrd[i][j] == (double)1.0)
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         cout << "The matrix isn't identity!!!" << endl;
//                         return false;
//                     }
//                 }
//             }
//         }
//         break;
//     }
//     case 3: //char array
//     {
//         int flag = 0;
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i != j)
//                 {
//                     if (mat[check].arrc[i][j] == 'z')
//                     {
//                     }
//                     else
//                     {
//                         flag = 0;
//                         cout << "The matrix isn't identity!!!" << endl;
//                         return false;
//                     }
//                 }
//                 if (i == j)
//                 {
//                     if (mat[check].arrc[i][j] == 'o')
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         cout << "The matrix isn't identity!!!" << endl;
//                         return false;
//                     }
//                 }
//             }
//         }
//         break;
//     }
//     case 4: //string array
//     {
//         int flag = 0;
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i != j)
//                 {
//                     transform(mat[check].arrs[i][j].begin(), mat[check].arrs[i][j].end(), mat[check].arrs[i][j].begin(), //convert to lowercase
//                               [](unsigned char c)
//                               { return std::tolower(c); });
//                     if (mat[check].arrs[i][j] == "zero")
//                     {
//                     }
//                     else
//                     {
//                         flag = 0;
//                         cout << "The matrix isn't identity!!!" << endl;
//                         return false;
//                     }
//                 }
//                 if (i == j)
//                 {
//                     transform(mat[check].arrs[i][j].begin(), mat[check].arrs[i][j].end(), mat[check].arrs[i][j].begin(), //convert to lowercase
//                               [](unsigned char c)
//                               { return std::tolower(c); });
//                     if (mat[check].arrs[i][j] == "one")
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         cout << "The matrix isn't identity!!!" << endl;
//                         return false;
//                     }
//                 }
//             }
//         }
//         break;
//     }
//     }
//     if (flag == 1)
//     {
//         cout << "The matrix is identity!!!" << endl;
//         return true;
//     }
// }
// //end of is_identity function

// //is_symmetrick function
// bool is_symmetric‬‬k(string command, struct store *mat)
// {
//     int pos = command.find(' ');
//     command = command.substr(pos + 1);
//     int check{-1};
//     for (size_t i = 0; i <= num; i++)
//     {
//         if (mat[i].name == command)
//         {
//             check = i;
//         }
//     }
//     if (check == -1)
//     {
//         cout << "Error...input name is invalid!!!" << endl;
//         return false;
//     }
//     if (mat[check].row != mat[check].column)
//     {
//         cout << "The matrix isn't symmetric‬‬k!!!" << endl;
//         return false;
//     }
//     switch (mat[check].check)
//     {
//     case 1: // int array
//     {
//         int flag = 0;
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i != j)
//                 {
//                     if (mat[check].arri[i][j] == mat[check].arri[j][i])
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         cout << "The matrix isn't normal symmetric‬‬k(also isn't skew symmetric)  " << endl;
//                         return false;
//                     }
//                 }
//             }
//         }
//         break;
//     }
//     case 2: // double array
//     {
//         int flag = 0;
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i != j)
//                 {
//                     if (mat[check].arrd[i][j] == mat[check].arrd[j][i])
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         cout << "The matrix isn't normal symmetric‬‬k(also isn't skew symmetric)  " << endl;
//                         return false;
//                     }
//                 }
//             }
//         }
//         break;
//     }
//     case 3: //char array
//     {
//         int flag = 0;
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i != j)
//                 {
//                     if (mat[check].arrc[i][j] == mat[check].arrc[j][i])
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         cout << "The matrix isn't normal symmetric‬‬k(also isn't skew symmetric)  " << endl;
//                         return false;
//                     }
//                 }
//             }
//         }
//         break;
//     }
//     case 4: //string array
//     {
//         int flag = 0;
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; j++)
//             {
//                 if (i != j)
//                 {
//                     transform(mat[check].arrs[i][j].begin(), mat[check].arrs[i][j].end(), mat[check].arrs[i][j].begin(), //convert to lowercase
//                               [](unsigned char c)
//                               { return std::tolower(c); });
//                     if (mat[check].arrs[i][j] == mat[check].arrs[i][j])
//                     {
//                         flag = 1;
//                     }
//                     else
//                     {
//                         cout << "The matrix isn't normal symmetric‬‬k(also isn't skew symmetric)  " << endl;
//                         return false;
//                     }
//                 }
//             }
//         }
//     }
//     }
//     if (command == "is_normal_symmetric‬‬")
//     {
//         cout << "The matrix is normal symmetric‬‬k" << endl;
//     }

//     if (command == "is_skew_symmetric‬‬")
//     {
//         cout << "The matrix is skew symmetric‬‬k" << endl;
//     }
//     return true;
// }
// //end of is_symmetrick function

// bool inverse(string command, struct store *mat)
// {
//     int check = 0;
//     int i = 0;
//     while (command[i] != '\0')
//     {
//         if (command[i] == ' ')
//         {
//             check = 1;
//             break;
//         }
//     }
//     string temp;
//     switch (check)
//     {
//     case 0:
//         int flag = -1; //
//         for (size_t i = 0; i <= num; i++)
//         {
//             if (mat[i].name == command)
//             {
//                 flag = i;
//             }
//         }
//         if (flag == -1)
//         {
//             cout << "Error...input name is invalid!!!" << endl;
//             return false;
//         }
//         if (mat[flag].row != mat[flag].column)
//         {
//             cout << "The matrix couldn't be a inverse matrix!!!" << endl;
//             return false;
//         }
//         switch (mat[num].check)
//         {
//         case 1:
//             for (size_t i = 0; i < mat[flag].row; i++)
//             {
//                 for (size_t j = 0; j < mat[flag].column; j++)
//                 {
//                     if (i != j)
//                     {
//                         mat[flag].arri[i][j] = mat[flag].arri[j][i];
//                     }
//                 }
//             }
//             break;
//         case 2:
//             for (size_t i = 0; i < mat[flag].row; i++)
//             {
//                 for (size_t j = 0; j < mat[flag].column; j++)
//                 {
//                     if (i != j)
//                     {
//                         mat[flag].arrd[i][j] = mat[flag].arrd[j][i];
//                     }
//                 }
//             }
//             break;
//         case 3:
//             for (size_t i = 0; i < mat[flag].row; i++)
//             {
//                 for (size_t j = 0; j < mat[flag].column; j++)
//                 {
//                     if (i != j)
//                     {
//                         mat[flag].arrc[i][j] = mat[flag].arrc[j][i];
//                     }
//                 }
//             }
//             break;
//         case 4:
//             for (size_t i = 0; i < mat[flag].row; i++)
//             {
//                 for (size_t j = 0; j < mat[flag].column; j++)
//                 {
//                     if (i != j)
//                     {
//                         mat[flag].arrs[i][j] = mat[flag].arrs[j][i];
//                     }
//                 }
//             }
//             break;
//         default:
//             break;
//         }
//         return true;
//     case 2:
//         int pos = command.find(' ');
//         temp = command.substr(pos + 1);
//         mat[num].name = temp; // add matrix
//         command = command.substr(0, pos);
//         flag = -1; //
//         for (size_t i = 0; i <= num; i++)
//         {
//             if (mat[i].name == command)
//             {
//                 flag = i;
//             }
//         }
//         if (flag == -1)
//         {
//             cout << "Error...input name is invalid!!!" << endl;
//             return false;
//         }
//         if (mat[flag].row != mat[flag].column)
//         {
//             cout << "The matrix couldn't be a inverse matrix!!!" << endl;
//             return false;
//         }
//         switch (mat[flag].check)
//         {
//         case 1: //int array
//             //copy matrix
//             for (size_t i = 0; i < mat[flag].row; i++)
//             {
//                 for (size_t j = 0; j < mat[flag].column; j++)
//                 {
//                     mat[num].arri[i][j] = mat[flag].arri[i][j];
//                 }
//             }
//             num++;
//             //inverse
//             for (size_t i = 0; i < mat[flag].row; i++)
//             {
//                 for (size_t j = 0; j < mat[flag].column; j++)
//                 {
//                     mat[num].arri[j][i] = mat[num].arri[i][j];
//                 }
//             }
//             break;
//         case 2: //double array
//             //copy matrix
//             for (size_t i = 0; i < mat[flag].row; i++)
//             {
//                 for (size_t j = 0; j < mat[flag].column; j++)
//                 {
//                     mat[num].arrd[i][j] = mat[flag].arrd[i][j];
//                 }
//             }
//             //inverse
//             for (size_t i = 0; i < mat[flag].row; i++)
//             {
//                 for (size_t j = 0; j < mat[flag].column; j++)
//                 {
//                     mat[num].arrd[j][i] = mat[num].arrd[i][j];
//                 }
//             }
//             num++;
//             break;
//         case 3: //char array
//             //copy matrix
//             for (size_t i = 0; i < mat[flag].row; i++)
//             {
//                 for (size_t j = 0; j < mat[flag].column; j++)
//                 {
//                     mat[num].arrc[i][j] = mat[flag].arrc[i][j];
//                 }
//             }
//             //inverse
//             for (size_t i = 0; i < mat[flag].row; i++)
//             {
//                 for (size_t j = 0; j < mat[flag].column; j++)
//                 {
//                     mat[num].arrc[j][i] = mat[num].arrc[i][j];
//                 }
//             }
//             num++;
//             break;
//         case 4: //string array
//             //copy matrix
//             for (size_t i = 0; i < mat[flag].row; i++)
//             {
//                 for (size_t j = 0; j < mat[flag].column; j++)
//                 {
//                     mat[num].arrs[i][j] = mat[flag].arrs[i][j];
//                 }
//             }
//             //inverse
//             for (size_t i = 0; i < mat[flag].row; i++)
//             {
//                 for (size_t j = 0; j < mat[flag].column; j++)
//                 {
//                     mat[num].arrs[j][i] = mat[num].arrs[i][j];
//                 }
//             }
//             num++;
//             break;
//         default:
//             break;
//         }
//         return true;
//     default:
//         cout << "command isn't invalid!!!" << endl;
//         break;
//     }
// }
// //end of inverse function

// //show function
// bool show(string command, struct store *mat)
// {
//     command = command.substr(5);
//     int check = -1;
//     for (size_t i = 0; i <= num; i++)
//     {
//         if (mat[i].name == command)
//         {
//             check = i;
//         }
//     }
//     if (check == -1)
//     {
//         cout << "Error...input name is invalid!!!" << endl;
//         return false;
//     }
//     switch (mat[check].check)
//     {
//     case 1: //int array
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; i++)
//             {
//                 cout << mat[check].arri[i][j] << "   ";
//             }
//             cout << endl;
//         }
//         break;
//     case 2:
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; i++)
//             {
//                 cout << mat[check].arrd[i][j] << "   ";
//             }
//             cout << endl;
//         }
//         break;
//     case 3:
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; i++)
//             {
//                 cout << mat[check].arrc[i][j] << "   ";
//             }
//             cout << endl;
//         }
//         break;
//     case 4:
//         for (size_t i = 0; i < mat[check].row; i++)
//         {
//             for (size_t j = 0; j < mat[check].column; i++)
//             {
//                 cout << mat[check].arrs[i][j] << "   ";
//             }
//             cout << endl;
//         }
//     default:
//         break;
//     }
//     return true;
// }
// //end of show function

// //delete function
// bool delete_matrix(string command, struct store *mat)
// {
//     command = command.substr(7);
//     int check = -1;
//     for (size_t i = 0; i <= num; i++)
//     {
//         if (mat[i].name == command)
//         {
//             check = i;
//         }
//     }
//     if (check == -1)
//     {
//         cout << "Error...input name is invalid!!!" << endl;
//         return false;
//     }
//     for (size_t i = check; i < num; i++)
//     {
//         mat[i] = mat[i + 1];
//     }
//     return true;
/*for (size_t i = check; i < num; i++)
    {
        mat[i].name = mat[i + 1].name;
        mat[i].row = mat[i + 1].row;
        mat[i].column = mat[i + 1].column;
        switch (mat[i].check)
        {
        case 1:
            for (size_t k = 0; k < mat[i].row; k++)
            {
                for (size_t j = 0; j < mat[i].column; j++)
                {
                    mat[num].arri[k][j] = mat[i + 1].arri[k][j];
                }
            }
            break;
        case 2:
            for (size_t k = 0; k < mat[i].row; k++)
            {
                for (size_t j = 0; j < mat[i].column; j++)
                {
                    mat[num].arrd[k][j] = mat[i + 1].arrd[k][j];
                }
            }
            break;
        case 3:
            for (size_t k = 0; k < mat[i].row; k++)
            {
                for (size_t j = 0; j < mat[i].column; j++)
                {
                    mat[num].arrc[k][j] = mat[i + 1].arrc[k][j];
                }
            }
        case 4:
            for (size_t k = 0; k < mat[i].row; k++)
            {
                for (size_t j = 0; j < mat[i].column; j++)
                {
                    mat[num].arrs[k][j] = mat[i + 1].arrs[k][j];
                }
            }
        default:
            break;
        }
    }
    return true;
}
//end of delete function

//change function
bool change(string command, struct store *mat)
{
    command = command.substr(7); //remove change
    int pos = command.find(' ');
    string temp = command.substr(0, pos);
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
    command = command.substr(pos + 1);
    switch (mat[check].check)
    {
    case 1: //int array
    {
        int i = 0; //use for command
        int arr[3];
        int k = 0; //use for arr
        while (command[i] != '\0')
        {
            if (isdigit(command[i]))
            {
                arr[k] = arr[k] * 10 + (command[i] - 48); // convert string to number
            }
            if (command[i] == ' ')
            {
                k++;
            }
            i++;
        }
        int row = arr[0];
        int column = arr[1];
        int new_num = arr[2];
        mat[num].arri[row][column] = new_num;
        break;
    }
    case 2: //double array
    {
        int i = 0; //use for command
        int arr[2];
        int k = 0; //use for arr
        string temp;
        bool ch = true;
        while(ch)
        {
            if (isdigit(command[i]))
            {
                arr[k] = arr[k] * 10 + (command[i] - 48); // convert string to number
            }
            if (command[i] == ' ')
            {
                k++;
            }
            if (k == 1)
            {
                temp = command.substr(i + 1);
                ch = false;
            }
            i++;
        }
        int row = arr[0];
        int column = arr[1];
        double new_num = stod(temp);
        mat[num].arrd[row][column] = new_num;
        break;
    }
    case 3: //char array
    {
        int i = 0; //use for command
        int arr[2];
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
            if (k == 1)
            {
                new_char = command[i + 1];
                ch = false;
            }

            i++;
        }
        int row = arr[0];
        int column = arr[1];
        mat[num].arrc[row][column] = new_char;
        break;
    }
    case 4: //string array
    {
        int i = 0; //use for command
        int arr[2];
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
            if (k == 1)
            {
                temp = command.substr(i + 1);
                ch = false;
            }
            
            i++;
        }
        int row = arr[0];
        int column = arr[1];
        mat[num].arrs[row][column] = temp;
        break;
    }
    default:
        break;
    }
    
}*/
/*case 1:
    {
        command = command.substr(pos1 + 1);
        for (pos1 = 0; isdigit(command[pos1]); pos1++)
        {
            column = column * 10 + (int(command[pos1] - 48)); // convert string to number
        }
        mat[num].row = row;
        mat[num].column = column;
        cout << "Enter a number for"
             << " row: " << 0 << " column: " << 0 << " ---> ";
        string temp ; //use recognize datatype of array
        cin>>temp;
        mat[num].check = 3;//if put the char
        if (isdigit(temp[0]))
        {
            if (!temp.find('.'))
            {
                mat[num].check = 2;
            }
            else
            {
                mat[num].check = 1;
            }
        }
        if (isdigit(temp[0]))
        {
            if (temp.length() > 1)
            {
                mat[num].check = 4;
            }
            
        }
        cout << mat[num].check << endl;
        if (mat[num].check == 1)
        {
            cout << "in int if "  << endl;
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
                }else
                {
                    j = 0;
                }
                for (; j < column; j++)
                {
                    cout << "Enter a number for"
                         << " row: " << i + 1 << " column: " << j + 1 << " ---> ";
                    cin >> mat[num].arri[i][j];
                }
            }
        }
        cout << mat[num].check << endl;
        if (mat[num].check == 2)
        {
            double first = stod(temp);
            cout << "in d if" << endl;
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
                }else
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
        if (mat[num].check == 4)
        {
            cout << "in char if" << endl;
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
                }else
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
        if (mat[num].check == 3)
        {
            cout << "in string if" << endl;
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
                }else
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
    }
        break;
    case 2:
    {
        column = row;
        mat[num].row = row;
        mat[num].column = column;
        command = command.substr(pos1 + 2);
        int pos2 = command.find(',');
        string temp = command.substr(0, pos2);
        if (isdigit(temp[0]))
        {
            if (!temp.find('.'))
            {
                mat[num].check = 2;
            }
            else
            {
                mat[num].check = 1;
            }
        }
        if (!isdigit(temp[0]))
        {
            if (temp.length() > 1)
            {
                mat[num].check = 4;
            }
            if (temp.length() == 1)
            {
                mat[num].check = 3;
            }
        }
        if (mat[num].check == 1)
        {
            int num3 = 0;           //use for convert string to number
            int fake[row * column]; // temp array for store number of array
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
        if (mat[num].check == 2)
        {
            string num3;               //use for convert string to number
            double num_double = 0;     //use for convert string to number
            double fake[row * column]; // temp array for store number of array
            cout << command << endl;
            double num_double = 0.0;
            int k = 0; // use in temp array
            int i = 0; //a var for while loop
            int j = 0;//use for fake array
            while (true)
            {
                if (command[i] == ']')
                {
                    num3 = command.substr(k, i);
                    num_double = stod(num3);
                    fake[j] = num_double;
                    break;
                }

                if (command[i] == ',')
                {
                    num3 = command.substr(k, i);
                    k = i + 1;
                    num_double = stod(num3);
                    fake[j] = num_double;
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

        if (mat[num].check == 3)
        {
            string num3;     //use for convert string to number
            string fake[row * column]; // temp array for store number of array
            cout << command << endl;
            int k = 0; // use in temp array
            int i = 0; //a var for while loop
            int j = 0;
            while (true)
            {
                if (command[i] == ']')
                {
                    num3 = command.substr(k, i);
                    fake[j] = num3;
                    break;
                }
                if (command[i] == ',')
                {
                    num3 = command.substr(k, i);
                    k = i + 1;
                    fake[j] = num3;
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
        if (mat[num].check == 4)
        {
            char num3 = nullptr;     //use for convert string to number
            char fake[row * column]; // temp array for store number of array
            cout << command << endl;
            int k = 0; // use in temp array
            int i = 0; //a var for while loop
            int j = 0;
            while (true)
            {
                if (command[i] == ']')
                {
                    num3 = command.substr(k, i);
                    fake[j] = num3;
                    break;
                }
                if (command[i] == ',')
                {
                    num3 = command.substr(k, i);
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
        int pos2 = command.find(',');
        string temp = command.substr(0, pos2);
        if (isdigit(temp[0]))
        {
            if (!temp.find('.'))
            {
                temp = "d";
                mat[num].check = 2;
            }
            else
            {
                temp = "i";
                mat[num].check = 1;
            }
        }
        if (!isdigit(temp[0]))
        {
            if (temp.length() > 1)
            {
                temp = "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE";
                mat[num].check = 4;
            }
            if (temp.length() == 1)
            {
                temp = "c";
                mat[num].check = 3;
            }
        }
        if (mat[num].check == 1)
        {
            int num3 = 0;           //use for convert string to number
            int fake[row * column]; // temp array for store number of array
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
                    fake[k] = num3;
                    num3 = 0;
                    k++;
                }
                i++;
            }
            fake[k] = num3;                   // initialize last number of string
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
                    mat[num].arr[i][j] = fake[k];
                    k++;
                }
            }
        }
        if (mat[num].check == 2)
        {
            string num3 ;     //use for convert string to number
            double fake[row * column]; // temp array for store number of array
            double num_double = 0;
            int k = 0; // use in temp array
            int i = 0; //a var for while loop
            int j = 0;
            while (true)
            {
                if (command[i] == ']')
                {
                    num3 = command.substr(k, i);
                    num_double = stod(num3);
                    fake[j] = num_double;
                    break;
                }

                if (command[i] == ',')
                {
                    m = command.substr(k, i);
                    k = i + 1;
                    num_double = stod(num3);
                    fake[j] = num_double;
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

        if (mat[num].check == 4)
        {
            string num3;     //use for convert string to number
            string fake[row * column]; // temp array for store number of array
            cout << command << endl;
            int k = 0; // use in temp array
            int i = 0; //a var for while loop
            int j = 0;
            while (true)
            {
                if (command[i] == ']')
                {
                    num3 = command.substr(k, i);
                    fake[j] = num3;
                    break;
                }
                if (command[i] == ',')
                {
                    num3 = command.substr(k, i);
                    k = i + 1;
                    fake[j] = num3;
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
        if (mat[num].check == 4)
        {
            char num3 = nullptr;     //use for convert string to number
            char fake[row * column]; // temp array for store number of array
            int k = 0; // use in temp array
            int i = 0; //a var for while loop
            int j = 0;
            while (true)
            {
                if (command[i] == ']')
                {
                    num3 = command.substr(k, i);
                    fake[j] = num3;
                    break;
                }
                if (command[i] == ',')
                {
                    num3 = command.substr(k, i);
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
    }*/
//     default:
//         cout << "Error in command!" << endl;
//         break;
//     }

//     return 0;
//}

//display function
// void display(struct store *mat)
// {
//     switch (mat[num].check)
//     {
//     case 1:
//         for (size_t i = 0; i < mat[num].row; i++)
//         {
//             for (size_t j = 0; j < mat[num].column; j++)
//             {
//                 cout << "row: " << i + 1 << "column: " << j + 1 << " " << mat[num].arri[i][j] << endl;
//             }
//         }

//         break;
//     case 2:
//         for (size_t i = 0; i < mat[num].row; i++)
//         {
//             for (size_t j = 0; j < mat[num].column; j++)
//             {
//                 cout << "row: " << i + 1 << "column: " << j + 1 << " " << mat[num].arrd[i][j] << endl;
//             }
//         }
//         break;
//     case 3:
//         for (size_t i = 0; i < mat[num].row; i++)
//         {
//             for (size_t j = 0; j < mat[num].column; j++)
//             {
//                 cout << "row: " << i + 1 << "column: " << j + 1 << " " << mat[num].arrc[i][j] << endl;
//             }
//         }
//         break;
//     case 4:
//         for (size_t i = 0; i < mat[num].row; i++)
//         {
//             for (size_t j = 0; j < mat[num].column; j++)
//             {
//                 cout << "row: " << i + 1 << "column: " << j + 1 << " " << mat[num].arrs[i][j] << endl;
//             }
//         }
//         break;
//     default:
//         break;
//     }
// }