typedef long long int lli;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
		set<lli> free;
		for (lli i = 0; i < n; i++) free.insert(i);
		priority_queue<pair<lli, lli>, vector<pair<lli, lli>>, greater<pair<lli, lli>>> in_progress; //{end_time, room_number}
		map<lli, lli> rooms;
		lli curr_time = 0;
		for (auto& it : meetings) {
			while (!in_progress.empty() && in_progress.top().first <= it[0]) {
				pair<lli, lli> curr = in_progress.top();
				in_progress.pop();
				free.insert(curr.second);
			}
			lli room_number = -1;
			lli end_time = it[1];
			if (free.empty()) {
				pair<lli, lli> curr = in_progress.top();
				in_progress.pop();
				free.insert(curr.second);
				end_time = max(curr.first, (lli)it[0]) + it[1] - it[0];
			}
			room_number = *(free.begin());
			free.erase(room_number);
			rooms[room_number]++;
			in_progress.push({end_time, room_number});
		}

		lli value = 0;
		lli ret = 0;
		for (lli i = 0; i < n; i++) {
			if (rooms[i] > value) {
				value = rooms[i];
				ret = i;
			}
		}
		return ret;
    }
};