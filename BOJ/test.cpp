#include <cstdio>

#define ALPHABET 26
#define IS_NULL(i) (!children[(i)])

class Trie {
private:
    Trie *children[ALPHABET];

    bool has_value = false;
    int len;

    int char_to_num(char ch) {
        return ch - 'a';
    }

public:
    Trie(int len) : len(len) {
        for (int i = 0; i < ALPHABET; i++)
            children[i] = 0;
    }

    void insert(char *str) {
        if (str[0] == '\0') {
            has_value = true;
            return;
        }

        int n = char_to_num(str[0]);

        if (IS_NULL(n)) {
            children[n] = new Trie(len + 1);
        }

        children[n]->insert(str + 1);
    }

    bool find(char *str) {
        if (str[0] == '\0') return has_value;

        int n = char_to_num(str[0]);

        if (IS_NULL(n)) {
            return false;
        } else {
            return children[n]->find(str + 1);
        }
    }
};

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    Trie trie(0);

    char str[512];

    while (N--) {
        scanf("%s", str);
        trie.insert(str);
    }

    int answer = 0;
    while (M--) {
        scanf("%s", str);
        answer += trie.find(str) ? 1 : 0;
        printf("%d\n",answer);
    }

    printf("%d", answer);
}
