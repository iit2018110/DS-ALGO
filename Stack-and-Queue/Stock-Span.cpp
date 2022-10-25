class StockSpanner {
private:
unordered_map<int, int> m_counts;
stack<int> m_stGreater;

public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if (m_stGreater.empty()) {
            m_stGreater.push(price);
            m_counts[price] = 1;
            return 1;
        }
        int count = 0;
        while (!m_stGreater.empty() && price >= m_stGreater.top()) {
            count += m_counts[m_stGreater.top()];
            m_stGreater.pop();
        }
        m_stGreater.push(price);
        m_counts[price] = (count + 1);
        return m_counts[price];
    }
};