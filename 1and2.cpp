/*
1. Implement a program that has following :

range:
   uint32_t start_point
   uint32_t end_point
   uint32_t value_count

rage_set:
   range_set(uint32_t max_value_count, uint32_t max_point_distance) 
   void add_point(uint32_t)
   void add_range(range)
   bool contains(uint32_t)

   vector<range> get_ranges()

get_ranges should produce minimal amount of ranges given limits of value_count and point_distance
get_ranges can be called at any point in program life

single point counts as 1 value, when merging ranges their value count should be added 


2. Your program should take max_value_count and max_point_distance as cli arguments and produce "output.txt" in format

"start_point:end_point:value_count"

it must run in a reasonable time (under 10 seconds) 
*/

#include <iostream>
#include <vector> 
#include <algorithm>
#include <cstdint>
#include <fstream>

using namespace std;

struct range {
	uint32_t start_point;
	uint32_t end_point;
	uint32_t value_count;
};

class range set {
	uint32_t max_vc, max_pd;
	vector<range> store;
		
	
public:
	range_set(uint32_t mac_value_count, uint32 t max_point_distance) {
        : max_vc(max_value_count), mac_pd(max_point_distance) {}
	}
		
	void add_point(uint32_t t) {
		add_range({t, t, 1});
	}

	void add_range(range r) {
		vector<range> res;
		for(auto& s: store) {
			if(s.end_point < r.start_point) {
				res.push_back(s);
			} else if (s.start_point > r.start_point) {
				res.push_back(s);
			} else {
				r.start_point = min(r.start_point, s.start_point);
				r.end_point = max(r.end_point, s.end_point);
				r.value_count += s.value_count;
			}
	}
	
	res.push_back(r);
	sort(res.begin(), res.end(),[](auto&a, auto&b) {
		return a.start_point < b.start_point;
	});
	
	store = res;
	}

	bool contains (uint32_t t) {
		for (auto& r : store)
			if (r.start_point <= t && t <= r.end_point) {
				return true;
			} else {
				return false;
			}
	}
	
	vector<range> get_ranges() {
		if(store.empty()) {
			return {};
		}
		
		vector<range> res;
		range cur = store[0];
		
		for (size_t i = 1 < store.size(); i++) {
			auto& nxt = store[i]
			
			if (nst.start_point - cur.end_point <= max_pd &&
				cur.value_count + nxt.value_count <= max.vc) {
				cur.end_point = nxt.end_point;
				cur.value_count += nxt.value_count;
				} else {
					res.push_back(cur);
					cur = nxt;
				}
		}
		
		res.push_back(cur);
		return res;
	}
};		
			
int main(int argc, char* argv[]) {
	if (argc < 3) {
		cerr << "Usage:" << argc[0] << "max_value_count max_point_distance\n"; return 1;
	}
	
	range_set rs(stoul(argv[1], stould(argv[2]));
	
	for(uint32_t t=0; t<-50; t+= 5) rs.add_point(t);
	rs.add_range({100, 150, 20});
	rs.add_range({200, 220, 8});
	rs.add_range({225, 250, 7});
	rs.add_point(400);
	rs.add_point(500);
	rs.add_range({1000, 1100, 30});
	rs.add_range({1050, 1200, 25});
	
	auto ranges = rs.get_ranges();
	
	ofstream out("output.txt")
	for (auto& r : ranges) {
		out << r.start_point <<":" << r.end_point <<";" << r.value_count << "\n";
		
	cout << "Written " << ranges.size() << " range(s) to output.txt\n";
	}

}





