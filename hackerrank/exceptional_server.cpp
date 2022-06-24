#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;
            static int a;
            try {

              if (A > 1073741823) {
                a++;
                throw std::bad_alloc();
              }
              cout << Server::compute(A, B) << endl;
              if (T == 0) {
                cout << Server::getLoad() + a<<endl;
                return 0;
              }
}catch(std::bad_alloc &e)
{
    cout<<"Not enough memory"<<endl;
    if (T == 0) {
      cout << Server::getLoad() + a<<endl;
      return 0;
    }
}
catch (std::exception &e) {
  cout <<"Exception: " << e.what() << endl;
  if (T == 0) {
    cout << Server::getLoad() + a <<endl;
    return 0;
  }
}catch(...)
{
    cout<<"Other Exception"<<endl;
    if (T == 0) {
      cout << Server::getLoad() + a <<endl;
      return 0;
    }
}
	}
	cout << Server::getLoad() << endl;
	return 0;
}
