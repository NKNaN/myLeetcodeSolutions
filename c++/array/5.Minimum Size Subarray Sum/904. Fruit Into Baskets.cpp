class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int sublo = 0;
        int subhi = 0;
        int maxlen = 0;
        int class_one = -1; 
        int class_one_idx = -1;// last index of class one
        int class_two = -1; 
        int class_two_idx = -1;// last index of class two
        int num_first_class = 0;
        int num_second_class = 0;
        bool overstack = 0;
        while (subhi < fruits.size() && !overstack) {
            // insert into basket
            if (numClasses(class_one, class_two) == 0) {
                class_one = fruits[subhi];
                class_one_idx = subhi;
                num_first_class++;
            } else if (numClasses(class_one, class_two) == 1) {
                if (fruits[subhi] == class_one) {
                    class_one_idx = subhi;
                    num_first_class++;
                } else {
                    class_two = fruits[subhi];
                    class_two_idx = subhi;
                    num_second_class++;
                }
            } else if (numClasses(class_one, class_two) == 2) {
                if (fruits[subhi] == class_one) {
                    class_one_idx = subhi;
                    num_first_class++;
                } else if (fruits[subhi] == class_two) {
                    class_two_idx = subhi;
                    num_second_class++;
                } else {
                    overstack = true;
                }
            }

            if (!overstack && subhi < fruits.size() ) {
                subhi++;
                if (subhi - sublo > maxlen) {
                    maxlen = subhi - sublo;
                }
            }
            
            if (overstack && fruits[subhi-1] == class_two) {
                while (overstack) {
                    if (fruits[sublo] == class_one) {
                        num_first_class--;
                    }
                    sublo++;
                    if (num_first_class == 0){
                        class_one = class_two;
                        class_one_idx = class_two_idx;
                        num_first_class = subhi - sublo;
                        class_two = -1;
                        class_two_idx = -1;
                        num_second_class = 0;
                        overstack = false;
                    }
                }
            }
            if (overstack && fruits[subhi-1] == class_one) {
                while (overstack) {
                    if (fruits[sublo] == class_two) {
                        num_second_class--;
                    }
                    sublo++;
                    if (num_second_class == 0){
                        num_first_class = subhi - sublo;
                        class_two = -1;
                        class_two_idx = -1;
                        num_second_class = 0;
                        overstack = false;
                    }
                }
            }    
            // cout<<"sublo: "<<sublo<<" subhi: "<<subhi<<endl;
            // cout<<"class_one: "<<class_one<<" class_two: "<<class_two<<endl;
            // cout<<"num_first_class: "<<num_first_class<<endl;
            // cout<<"num_second_class: "<<num_second_class<<endl;
            // cout<<maxlen<<endl;
        }
        return maxlen;
    }

    int numClasses(int class_one, int class_two) {
        if (class_one == -1 && class_two == -1) {
            return 0;
        } else if (class_one != -1 && class_two != -1) {
            return 2;
        } else {
            return 1;
        }
    }
};