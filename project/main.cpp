#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include "function.h"
using namespace std;
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
    exit(matrix);
    delete [] matrix;
    return 0;
}