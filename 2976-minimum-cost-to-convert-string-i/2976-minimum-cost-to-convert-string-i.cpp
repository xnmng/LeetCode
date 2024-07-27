class Solution {
public:
    // floyd-warshall to determine all pairs shortest path, then calculate ans
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        int m = original.size();
        long long ans = 0;
        vector<vector<int>> v(26, vector<int>(26, 1e9));
        for (int i = 0; i < 26; ++i) v[i][i] = 0;
        for (int i = 0; i < m; ++i) {
            // might have duplicate mappings; use the 'cheapest' one
            v[original[i] - 'a'][changed[i] - 'a'] = min(v[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                }
            }
        }
        
        for (auto i = 0; i < n; ++i) {
            if (v[source[i] - 'a'][target[i] - 'a'] == 1e9) return -1;
            ans += v[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};
// "ahymwvveassnabpnivvlhwnymipzyywplahbppaeisazybzbuyveobnollbmlubwehounmhepwsyallupvhuawlvoszyiwlabulzhvmiulilmysvsezbhbylaowmbybpylozvnublnsyweapaauhehswollnmlbeoanennnuoybymnnyhlmmvivbhwmhnibspusezippnybyhyzzbypyamlsylhiinlmwveibnmwpspmnnlmpnzmapouposwowavimbhuaoosiewymbiuwaoesblyhpoebhapnaeiveiezznwzoowhmsbvoiziiymelohboohmvzishzviabwzuzoamysphamowvlwlmmoyoyzewuowbhupobwzzouhllszpsnyubnaheyaouozuzpelomhpwezevyuobbhnwnlyeyusoslenbolmeunaopvhanibpvvloiplhobipzbobsbsbbhpyvoslhwupwvhsyhizluziahamay"
// "iwevmnllzbiespsmeoeunnvzuymnymvoeyuyhozuminepwaezpeeayhualvhlboeewaboosplonuzheuziyymhbnywnwzyameyshvbhnzvvbeznniaswzslzbsasvbewzzzmvulvvhzmohzmyummypaeowusvlmlyvmvaizuvomvipbpwnbimppoymiesmymioeemzpbwbvuszpvbpwmnyvypyzemsniaavnmiphiyvimzoozuepbowbpvmpelahvupuwzlbbywvyusawobouslblvbpvluylnsiauiwzawiowsnmvawepielbavvpbmvylvlylzunmbnaesoimuvwsmybmnybbhwbyuimmoebpvwnpiyebzzuwhiovubuynyvybipbzsnuopuhpzosmnhlnlmnneumshwaiyyspbpbiaiovyyvomhanunieisazshvyubmbvnbpiwipmuzbymnozwzaaawenlwiowpsvleppzellhei"
// ["n","s","a","s","s","b","h","l","e","n","e","w","y","m","n","e","a","n","p","n","u","i","b","m","z","s","v","o","n","n","a","o","l","p","s","v","b","h","b","s","y","i","a","v","o","p","p","l","a","p","o","e","l","a","m","h","o","v","e","s","n","w","v","w","y","n","o","o","e","e","h","h","z","z","z","s","s","z","h","y","u","i","l","y","h","u","s","e","b","b","o","h","p","l","e","n","v","l","s","h","m","z","z","h","z","b","w","u","o","b","u","m","o","b","e","n","a","v","b","b","n","i","l","h","a","p","w","p","i","u","n","b","h","b","b","n","s","v","u","n","v","v","e","h","l","s","l","o","s","o","b","i","i","n","e","h","u","i","w","w","u","b","s","z","h","b","l","e","a","o","m","z","l","n","o","v","v","e","h","e","v","e","l","i","s","s","y","b","w","o","i","s","h","b","b","y","e","y","h","o","p","s","i","p","n","l","w","y","u","a","v","y","s","l","v","w","z","l","p","m","w","s","y","b","w","z","w","n","e","s","e","e","e","s","a","n","o","y","i","y","o","e","o","e","w","n","h","s","v","l"...
// ["z","u","z","i","z","y","w","e","m","b","u","l","l","u","e","s","n","s","m","b","p","y","w","v","m","y","l","b","h","i","y","b","o","l","u","i","e","v","o","w","p","a","z","u","i","o","b","w","m","b","n","a","y","y","v","a","v","m","s","m","v","n","e","m","o","h","p","n","w","s","y","n","w","y","u","m","a","y","s","m","n","e","w","e","u","m","m","z","z","z","v","i","w","s","y","v","i","a","y","m","y","b","p","e","v","z","y","p","a","m","b","y","s","o","n","w","n","h","m","z","u","n","b","e","v","s","o","z","z","b","y","i","w","n","l","s","y","i","w","b","u","e","i","u","m","m","w","b","i","s","m","p","v","u","u","w","m","a","l","m","w","s","u","p","w","m","h","n","s","s","v","e","u","z","v","e","u","a","l","p","l","y","n","p","u","m","b","l","h","s","a","y","s","n","p","m","m","v","u","b","l","u","u","b","m","o","b","p","a","y","l","w","i","y","i","e","m","m","n","s","o","z","u","h","v","b","u","b","i","u","p","z","w","z","s","o","m","p","w","z","n","n","l","n","p","m","y","u","e","n"...
// [745546,681763,567802,714000,250223,676168,444410,527553,539719,237541,696428,560465,863906,796296,428070,18490,54402,542636,460145,966528,362462,104880,646640,461359,97243,827845,398969,647258,941991,742668,890530,756048,250972,626893,855304,619312,569762,925139,241103,548379,142738,237066,643035,81116,653135,438231,217017,511962,589779,761220,274768,576117,512613,532612,911093,165413,607172,256053,330723,280576,539232,29355,86424,843231,510568,531223,335530,169903,595277,970232,781022,457910,514351,153815,49601,994502,179631,869857,32952,333217,915309,887802,802546,273560,659751,996122,771046,983170,958044,187888,526229,610546,507368,296596,62715,549555,574593,673622,308748,272856,412850,912078,327031,989337,488811,981765,661273,708178,402096,678953,64500,565907,29632,266317,162603,498262,149281,198824,415695,582258,710013,632530,593250,726557,376302,556283,723094,103059,563190,930834,413921,912243,942797,809930,205611,360333,505711,403206,511661,757042,2587,65183,638120,900128,24410...