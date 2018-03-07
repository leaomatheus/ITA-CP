#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

typedef tree<
pair<int,int>,
null_type,
less<pair<int,int> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

typedef pair<int,int> ii;

char command[40];
int id_cnt = 0;
map<string, int> code_to_id;
int reliab[100005];
ordered_set teste;
vector<string> all_codes;

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%s", command);
		string com = command;
		
		if (com == "ISSUE") {
			scanf("%s", command);
			string code = command;
			
			if (code_to_id.find(code) == code_to_id.end()) {
				printf("CREATED %d 0\n", id_cnt);
				teste.insert(ii(0, id_cnt));
				code_to_id[code] = id_cnt++;
				all_codes.push_back(code);
				
			} else {
				int id = code_to_id[code];
				printf("EXISTS %d %d\n", id, reliab[id]);
			}
		} else if (com == "DELETE") {
			scanf("%s", command);
			string code = command;
			
			if (code_to_id.find(code) == code_to_id.end()) {
				printf("BAD REQUEST\n");
			} else {
				int id = code_to_id[code];
				code_to_id.erase(code);
				teste.erase(ii(-reliab[id], id));
				
				printf("OK %d %d\n", id, reliab[id]);
			}
		} else if (com == "RELIABILITY") {
			int m;
			scanf("%s %d", command, &m);
			string code = command;
			
			if (code_to_id.find(code) == code_to_id.end()) {
				printf("BAD REQUEST\n");
			} else {
				int id = code_to_id[code];
				
				teste.erase(ii(-reliab[id], id));
				reliab[id] += m;
				teste.insert(ii(-reliab[id], id));
				printf("OK %d %d\n", id, reliab[id]);
			}
		} else if (com == "FIND") {
			int m;
			scanf("%d", &m);
			m = min(m, (int)code_to_id.size() - 1);
			if (code_to_id.empty()) {
				printf("EMPTY\n");
			} else {
				pair<int,int> tmp = *teste.find_by_order(m);
				int id = tmp.second;
				printf("OK %s %d %d\n", all_codes[id].c_str(), id, reliab[id]);
			}
		}
	}
}