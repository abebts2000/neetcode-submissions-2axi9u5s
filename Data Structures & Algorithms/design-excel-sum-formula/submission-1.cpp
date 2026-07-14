class Excel {
public:
    int H;
    int W;
    struct Cell {
        int val = 0;
        map<pair<int, int>, int> formula; // coordinates -> count
    };
    vector<vector<Cell>> sheet;

    Excel(int height, char width) {
        H = height;
        W = width - 'A' + 1;
        sheet.resize(H + 1, vector<Cell>(W + 1));
    }
    
    void set(int row, char column, int val) {
        int col = column - 'A' + 1;
        sheet[row][col].val = val;
        sheet[row][col].formula.clear();
    }
    
    int get(int row, char column) {
        int col = column - 'A' + 1;
        if (sheet[row][col].formula.empty()) {
            return sheet[row][col].val;
        }
        int total = 0;
        for (auto const& [pos, count] : sheet[row][col].formula) {
            total += get(pos.first, pos.second + 'A' - 1) * count;
        }
        return total;
    }
    
    int sum(int row, char column, vector<string> numbers) {
        int col = column - 'A' + 1;
        sheet[row][col].formula.clear();
        for (const string& s : numbers) {
            size_t colonPos = s.find(':');
            if (colonPos == string::npos) {
                pair<int, int> pos = parse(s);
                sheet[row][col].formula[pos]++;
            } else {
                pair<int, int> start = parse(s.substr(0, colonPos));
                pair<int, int> end = parse(s.substr(colonPos + 1));
                for (int r = start.first; r <= end.first; ++r) {
                    for (int c = start.second; c <= end.second; ++c) {
                        sheet[row][col].formula[{r, c}]++;
                    }
                }
            }
        }
        return get(row, column);
    }

private:
    pair<int, int> parse(string s) {
        int col = s[0] - 'A' + 1;
        int row = stoi(s.substr(1));
        return {row, col};
    }
};