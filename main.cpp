#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kangaroo' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER v1
 *  3. INTEGER x2
 *  4. INTEGER v2
 */

string kangaroo(int x1, int v1, int x2, int v2) {
    int kangaroo1Position = 0;
    int kangaroo2Position = 0;
    bool positionMatch = false;
    string strpositionMatch = "";
    kangaroo1Position = x1 + v1;
    kangaroo2Position = x2 + v2;
    bool biggerJumpInLead = false;

    if ((x1 > x2 && v1 > v2) || (x1 < x2 && v1 < v2)) {
        positionMatch = false;
    }
    else if (((x1 > x2) && (v1 == v2)) || (x2 > x1) && (v2 == v1)) {
        positionMatch = false;
    }
    else {
        if (kangaroo1Position == kangaroo2Position ) {
            positionMatch = true;
        }
        while (!positionMatch && !biggerJumpInLead) {
            //if the kangaroo with the great jump size moves ahead, break out of loop.
            kangaroo1Position += v1;
            kangaroo2Position += v2;
            if (kangaroo1Position == kangaroo2Position) {
                positionMatch = true;
            }
            else if ((kangaroo1Position > kangaroo2Position) && (v1 > v2)) {
                biggerJumpInLead = true;
            }
            else if ((kangaroo2Position > kangaroo1Position) && (v2 > v1)) {
                biggerJumpInLead = true;
            }
        }
    }

    //X1 & X2 are kangaroo 1 & 2 starting positions respectively.
    //V1 & V2 are kangaroo 1 & 2's distance per "jump"

    if (positionMatch) {
        strpositionMatch = "YES";
    }
    else {
        strpositionMatch = "NO";
    }
    return strpositionMatch;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int x1 = stoi(first_multiple_input[0]);

    int v1 = stoi(first_multiple_input[1]);

    int x2 = stoi(first_multiple_input[2]);

    int v2 = stoi(first_multiple_input[3]);

    if ((x1 < x2) && (x1 >= 0 && x1 <= 10000) && (x2 >= 0 && x2 <= 10000)
        && (v1 >= 1 && v1 <= 10000) && (v2 >= 1 && v2 <= 10000)) {
        string result = kangaroo(x1, v1, x2, v2);
        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
