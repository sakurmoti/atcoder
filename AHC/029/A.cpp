#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAX_INVEST_LEVEL = 20;
constexpr ll INVEST_COST[] = 
{
    1, 2, 4, 8, 16, 32, 64, 128, 256, 512,
    1024, 2048, 4096, 8192, 16384, 32768,
    65536, 131072, 262144, 524288, 1048576
};

struct Project {
    ll h;
    ll v;

    const Project operator*(const int& n) const {
        return Project{h * n, v * n};
    }
};

enum class CardType {
    WORK_SINGLE = 0,
    WORK_ALL = 1,
    CANCEL_SINGLE = 2,
    CANCEL_ALL = 3,
    INVEST = 4,
};

ostream& operator<<(ostream& os, CardType ct) {
    switch(ct) {
        case CardType::WORK_SINGLE:
            os << "WORK_SINGLE";
            break;
        case CardType::WORK_ALL:
            os << "WORK_ALL";
            break;
        case CardType::CANCEL_SINGLE:
            os << "CANCEL_SINGLE";
            break;
        case CardType::CANCEL_ALL:
            os << "CANCEL_ALL";
            break;
        case CardType::INVEST:
            os << "INVEST";
            break;
    }
    return os;
}

struct Card {
    CardType t;
    ll w;
    ll p;

    const Card operator*(const int& n) const {
        return Card{t, w * n, p * n};
    }
};

/* ------------------------------ */

#define DEBUG
#ifdef DEBUG
    vector<Project> init_project;
    queue<Project> new_project;
    vector<Card> init_card;
    vector<vector<Card>> new_card;
#endif


/* ------------------------------  */

struct Judge {
    const int n;
    const int m;
    const int k;

    Judge(int n, int m, int k): n(n), m(m), k(k) {}

    vector<Card> read_initial_cards() {
        #ifdef DEBUG
            return init_card;
        #endif
        
        vector<Card> cards;
        for (int i = 0; i < n; i++) {
            ll t, w;
            cin >> t >> w;
            cards.push_back(Card{(CardType)t, w, 0ll});
        }
        return cards;
    }

    vector<Project> read_projects() {
        #ifdef DEBUG
            return init_project;
        #endif

        vector<Project> projects;
        for (int i = 0; i < m; i++) {
            ll h, v;
            cin >> h >> v;
            projects.push_back(Project{h, v});
        }
        return projects;
    }

    void use_card(int c, int m) {
        cout << c << " " << m << endl;
    }

    ll read_money() {
        ll money;
        cin >> money;
        return money;
    }

    vector<Card> read_next_cards(int turn) {
        #ifdef DEBUG
            return new_card[turn];
        #endif

        vector<Card> cards;
        for (int i = 0; i < k; i++) {
            ll t, w, p;
            cin >> t >> w >> p;
            cards.push_back(Card{(CardType)t, w, p});
        }
        return cards;
    }

    void select_card(int r) {
        cout << r << endl;
    }

    void comment(const string& message) {
        cout << "# " << message << endl;
    }
};

struct Solver {
    const int n;
    const int m;
    const int k;
    const int t;
    Judge judge;
    int turn;
    int invest_level;
    ll money;
    vector<Project> projects;
    vector<Card> cards;


    Solver(int n, int m, int k, int t) : 
        n(n), m(m), k(k), t(t), judge(n, m, k), turn(0), invest_level(0), money(0) {
    }

    ll solve() {
        cards = judge.read_initial_cards();
        projects = judge.read_projects();
        for (turn = 0; turn < t; ++turn) {
            auto [use_card_i, use_target] = select_action();
            const Card& use_card = cards[use_card_i];
            if (use_card.t == CardType::INVEST) {
                invest_level++;
            }
            // example for comments
            stringstream msg;
            msg << "used Card(t=" << use_card.t << " w=" << use_card.w << " p=" << use_card.p << ") to target " << use_target;
            judge.comment(msg.str());
            judge.use_card(use_card_i, use_target);
            assert(invest_level <= MAX_INVEST_LEVEL);

            #ifdef DEBUG
                // moneyが与えられないので自分で計算する
                switch(use_card.t) {
                    case CardType::WORK_SINGLE:
                        projects[use_target].h -= use_card.w;
                        if(projects[use_target].h <= 0){
                            money += projects[use_target].v;
                            projects[use_target] = new_project.front() * INVEST_COST[invest_level];
                            new_project.pop();
                        }
                        break;

                    case CardType::WORK_ALL:
                        for(int i = 0; i < m; i++){
                            projects[i].h -= use_card.w;
                            if(projects[use_target].h <= 0){
                                money += projects[use_target].v;
                                projects[i] = new_project.front() * INVEST_COST[invest_level];
                                new_project.pop();
                            }
                        }
                        break;

                    case CardType::CANCEL_SINGLE:
                        projects[use_target] = new_project.front() * INVEST_COST[invest_level];
                        new_project.pop();
                        break;

                    case CardType::CANCEL_ALL:
                        for(int i = 0; i < m; i++){
                            projects[i] = new_project.front() * INVEST_COST[invest_level];
                            new_project.pop();
                        }
                        break;

                    case CardType::INVEST:
                        // 上ですでにinvest_level++しているので特に操作しなくても良い
                        break;
                }
            #endif

            #ifndef DEBUG
                projects = judge.read_projects();
                money = judge.read_money();
            #endif

            vector<Card> next_cards = judge.read_next_cards(turn);
            int select_card_i = select_next_card(next_cards);
            cards[use_card_i] = next_cards[select_card_i];
            judge.select_card(select_card_i);
            money -= next_cards[select_card_i].p;
            assert(money >= 0);
        }
        return money;
    }

    pair<int, int> select_action() {
        // TODO: implement your strategy
        return {0, 0};
    }

    int select_next_card(const vector<Card>& next_cards) {
        // TODO: implement your strategy
        return 0;
    }
};

int main(void) {
    #ifdef DEBUG
        // ファイル入出力に切り替え
        string seed = "0000";
        ifstream input("./input/" + seed + ".txt");
        if(!input){
            cerr << "No input file";
            return 0;
        }
        cin.rdbuf(input.rdbuf());

        ofstream output("./output/" + seed + ".txt");
        cout.rdbuf(output.rdbuf());
    
    
    #endif

    int n, m, k, t;
    cin >> n >> m >> k >> t;

    #ifdef DEBUG
        // visualizer用の入力
        for(int i = 0; i < m; i++){
            ll h,v; cin >> h >> v;
            init_project.push_back(Project{h,v});
        }
        
        for(int i = 0; i < t*m; i++){
            ll h,v; cin >> h >> v;
            new_project.push(Project{h,v});
        }
        for(int i = 0; i < n; i++){
            ll t,w; cin >> t >> w;
            init_card.push_back(Card{CardType(t), w, 0ll});
        }
        new_card.resize(t);
        for(int i = 0; i < t; i++){
            for(int j = 0; j < k; j++){
                ll t,w,p; cin >> t >> w >> p;
                new_card[i].push_back(Card{CardType(t), w, p});
                // cout << (int)new_card[i][j].t << " " << new_card[i][j].w << " " << new_card[i][j].p << endl;
            }
        }
    #endif

    Solver solver(n, m, k, t);
    ll score = solver.solve();
    cerr << "score:" << score << endl;
}
