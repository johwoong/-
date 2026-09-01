#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    int min_press[26];
    for (int i = 0; i < 26; i++) {
        min_press[i] = 101;
    }

    for (const string& key : keymap) {
        for (int i = 0; i < key.length(); i++) {
            char ch = key[i];
            int press_count = i + 1;

            if (press_count < min_press[ch - 'A']) {
                min_press[ch - 'A'] = press_count;
            }
        }
    }

    for (const string& target : targets) {
        int total_press = 0;
        bool possible = true;

        for (char ch : target) {
            int press = min_press[ch - 'A'];

            if (press == 101) {
                possible = false;
                break;
            }

            total_press += press;
        }

        if (possible) {
            answer.push_back(total_press);
        }
        else {
            answer.push_back(-1);
        }
    }

    return answer;
}

int main() {
    vector<string> keymap = { "ABACD", "BCEFD" };
    vector<string> targets = { "ABCD", "AABB" };

    vector<int> result = solution(keymap, targets);

    cout << "°á°ú: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}