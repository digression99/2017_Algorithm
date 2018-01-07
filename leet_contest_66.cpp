/*
 leetcode_contest_66
 
 */

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <deque>

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> hashB;
        vector<int> ans;
        
        for (int i = 0; i < A.size(); ++i) {
            hashB[B[i]] = i;
        }
        
        for (int i = 0; i < A.size(); ++i) {
            ans.push_back(hashB[A[i]]);
        }
        
        return ans;
    }
    
    string boldWords(vector<string>& words, string S) {
        // find all appearances in a given word.
        string res = "";
        deque<pair<int, int>> pos;
        
        for (int i = 0; i < words.size(); ++i) {
            size_t lastStart = 0;
            size_t start = S.find(words[i], lastStart);
            
            while (start != string::npos) {
//                lastStart = start + 1;
                pos.push_back(make_pair(start, start + words[i].length())); // start, end.
                lastStart = start + words[i].length();
                start = S.find(words[i], lastStart);
            }
        }
        
        sort(pos.begin(), pos.end());
        int lastEnded = 0;
        
        while (pos.size() > 0) {
            if (pos.size() > 1 && pos[0].second >= pos[1].first) {
                int start = pos[0].first;
                int end = pos[0].second > pos[1].second ? pos[0].second : pos[1].second;
                pos.pop_front();
                pos.pop_front();
                pos.push_front(make_pair(start, end));
            } else {
                res.append(S.substr(lastEnded, pos[0].first - lastEnded));
                res.append("<b>" + S.substr(pos[0].first, pos[0].second - pos[0].first) + "</b>");
                lastEnded = pos[0].second;
                pos.pop_front();
            }
        }
        
        if (lastEnded < S.length())
            res.append(S.substr(lastEnded, S.length() - lastEnded));
        
        return res;
    }
};

/*
 ["ccb","b","d","cba","dc"]
 "eeaadadadc"
 res : "eeaa<b>d</b>a<b>d</b>a<b>dc</b>"
 
 ["b","dee","a","ee","c"]
 "cebcecceab"
 res : "<b>c</b>e<b>bc</b>e<b>cc</b>e<b>ab</b>"
 
 ["di","r","buhozb","lofjmyjj","qagllw","zzuid","loyugfh","w","hcfg","ttd","vjqigvx","u","mhbivve","x","nzbvyfzx","zs","j","zgtud","zm","huevyex","szwigrlwzm","vlrjmobu","b","h","gcmdgyv","anyfelm","vtcejv","myjjzn","jznnj","awcxmjn","lw","sju","szszwigrl","eze","ffikvecua","bklrhsju","gyazwel","pdhnsxsod","zn","rhsjus","zk","gctgu","vzndt","mfd","jlws","j","zxgaudyo","apa","znvixpdh","tgubzczgt"]
 "wwcyuaqzgtudmpjkluqoseslygywzkixjqghsocvjqigvxwqloyugfhcjscjghqmiglgyazwelshzapaezqgmcmrmfrfzttdgquizyducbvxzzuiddcnwuaapdunzlbagnifndbjyalqqgbramhbivvervxrtcszszwigrlwzmuteyswzagudtpvlrjmobuhozbghkhvoxawcxmjnazlqlkqqqnoclufgkovbokvkoezeknwhcfgcenvaablpvtcejvzndtzncrelhedwlwiqgdbdgctgubzczgtovufncicjlwsmfdcrqeaghuevyexqdhffikvecuazrelofjmyjjznnjdkimbklrhsjusbstqhvlejtjcczqnzbvyfzxgaudyosckysmminoanjmbafhtnbrrzqagllwxlxmjanyfelmwruftlzuuhbsjexoobjkmymlitiwjtdxscotzvznvixpdhnsxsodieatipiaodgcmdgyv"
 
 res : "<b>ww</b>cy<b>u</b>aq<b>zgtud</b>mp<b>j</b>kl<b>u</b>qoseslygy<b>wzk</b>i<b>xj</b>qg<b>h</b>soc<b>vjqigvxw</b>q<b>loyugfh</b>c<b>j</b>sc<b>j</b>g<b>h</b>qmigl<b>gyazwel</b>s<b>h</b>z<b>apa</b>ezqgmcm<b>r</b>mf<b>r</b>fz<b>ttd</b>gq<b>u</b>izyd<b>u</b>c<b>b</b>v<b>xzzuid</b>dcn<b>wu</b>aapd<b>u</b>nzl<b>b</b>agnifnd<b>bj</b>yalqqg<b>br</b>a<b>mhbivver</b>v<b>xr</b>tc<b>szszwigrlwzmu</b>teys<b>w</b>zag<b>u</b>dtp<b>vlrjmobuhozb</b>g<b>h</b>k<b>h</b>vo<b>xawcxmjn</b>azlqlkqqqnocl<b>u</b>fgkov<b>b</b>okvko<b>eze</b>kn<b>whcfg</b>cenvaa<b>b</b>lp<b>vtcejvzndtzn</b>c<b>r</b>el<b>h</b>ed<b>wlw</b>iqgd<b>b</b>d<b>gctgubzczgt</b>ov<b>u</b>fncic<b>jlwsmfd</b>c<b>r</b>qeag<b>huevyex</b>qd<b>hffikvecua</b>z<b>r</b>e<b>lofjmyjjznnj</b>dkim<b>bklrhsjusb</b>stq<b>h</b>vle<b>j</b>t<b>j</b>cczq<b>nzbvyfzxgaudyo</b>sckysmminoan<b>j</b>m<b>b</b>af<b>h</b>tn<b>brr</b>z<b>qagllwx</b>l<b>x</b>m<b>janyfelmwru</b>ftlz<b>uuhb</b>s<b>j</b>e<b>x</b>oo<b>bj</b>kmymliti<b>wj</b>td<b>x</b>scotzv<b>znvixpdhnsxsodi</b>eatipiaod<b>gcmdgyv</b>"
 */

int main() {
    Solution obj = Solution();
    //vector<string> words = {"ab", "bc"};
    //string S = "aabcd";
//    vector<string> words2 = {"ccb","b","d","cba","dc"};
//    string S2 = "eeaadadadc";
//    vector<string> words3 = {"b","dee","a","ee","c"};
//    string S3 = "cebcecceab";
    vector<string> words4 = {"di","r","buhozb","lofjmyjj","qagllw","zzuid","loyugfh","w","hcfg","ttd","vjqigvx","u","mhbivve","x","nzbvyfzx","zs","j","zgtud","zm","huevyex","szwigrlwzm","vlrjmobu","b","h","gcmdgyv","anyfelm","vtcejv","myjjzn","jznnj","awcxmjn","lw","sju","szszwigrl","eze","ffikvecua","bklrhsju","gyazwel","pdhnsxsod","zn","rhsjus","zk","gctgu","vzndt","mfd","jlws","j","zxgaudyo","apa","znvixpdh","tgubzczgt"};
    string S4 = "wwcyuaqzgtudmpjkluqoseslygywzkixjqghsocvjqigvxwqloyugfhcjscjghqmiglgyazwelshzapaezqgmcmrmfrfzttdgquizyducbvxzzuiddcnwuaapdunzlbagnifndbjyalqqgbramhbivvervxrtcszszwigrlwzmuteyswzagudtpvlrjmobuhozbghkhvoxawcxmjnazlqlkqqqnoclufgkovbokvkoezeknwhcfgcenvaablpvtcejvzndtzncrelhedwlwiqgdbdgctgubzczgtovufncicjlwsmfdcrqeaghuevyexqdhffikvecuazrelofjmyjjznnjdkimbklrhsjusbstqhvlejtjcczqnzbvyfzxgaudyosckysmminoanjmbafhtnbrrzqagllwxlxmjanyfelmwruftlzuuhbsjexoobjkmymlitiwjtdxscotzvznvixpdhnsxsodieatipiaodgcmdgyv";
    
    cout << obj.boldWords(words4, S4) << endl;
    
    return 0;
}

