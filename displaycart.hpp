#include <iostream>
#include <fstream>
using namespace std;
string displaycart()
{
    ifstream file("Record.txt", ios::out);
    if (!file) {
        cerr << "Unable to open file"<< endl;
        return "";
    }
    string line;
    string content;
    while (getline(file, line)) {
        cout << line << endl;
        content += line + "\n";// Add a newline character after each line
    }
    file.close();
    return content;
}
int main() {
    string cartContent = displaycart();
    cout << "Cart Content:\n" << cartContent;
    return 0;
}