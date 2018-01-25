//
// Created by Dicky Shi on 6/13/17.
//

//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <ctime>
#include "utils.h"

using namespace std;

class Solution {
public:
    bool isPalindrome (string s) {
        if (s.size() == 0) return true;
        string::size_type first=0, last=s.size()-1;
        while (first < last) {
            if (s[first] != s[last]) {
                return false;
            }
            ++first;--last;
        }
        return true;
    }

    vector<vector<int> > palindromePairs(vector<string>& words) {

        vector<vector<int> > results;
        unordered_map<string, int> hash;

        /* put reversed words in hashmap */
        for (int i = 0; i < words.size(); ++i) {
            string s = words[i];
            reverse(s.begin(), s.end());
            hash[s] = i;
        }

        /* deal with empty string edge case */
        if (hash.find("") != hash.end()) {
            for (int i = 0; i < words.size(); ++i) {
                if (isPalindrome(words[i])) {
                    results.push_back({hash[""], i});
                }
            }
        }

        /* for every word, split it into two parts
         * check whether left part or right part is
         * in hashmap. If so, then this word and the
         * reverse index would become palindrome */
        for (int i = 0; i < words.size(); ++i) {
            for (string::size_type j = 0; j < words[i].size(); ++j) {
                string s1 = words[i].substr(0, j);
                string s2 = words[i].substr(j, words.size()-j);

                if (hash.find(s1) != hash.end() && isPalindrome(s2) && hash[s1] != i) {
                    results.push_back({i, hash[s1]});
                }
                if (hash.find(s2) != hash.end() && isPalindrome(s1) && hash[s2] != i) {
                    results.push_back({hash[s2], i});
                }
            }
        }

        return results;
    }
};

int main() {
    clock_t start = clock();
    std::vector<std::string> words = {"abcd", "dcba", "lls", "s", "sssll"};
//    std::vector<std::string> words = {"bgcahbciadagghie","cajgfcbegieehcd","jfacifeejiijaccae","jbcicdiebddejceeb","hje","ciaafiabgcjjd","abcfecacgbjejieghd","eeeaeej","gegagdabegbeffhabdi","ejb","fbbdfffbbgdafagegd","ecbgdfdabbfehcdfbcj","acaddeaidebiedddd","gh","eefigccahg","jgcehbbbhccee","bacbhaaffbadhcej","ieaehbeajbibig","caaaj","jf","higidc","dbjjfcdge","bbgcjeiaig","eaehbehfcgeacfajdj","ibgeih","bfgg","fcbhe","ajcfefhafgbdicdaddhe","jjh","cgd","agjjafci","jjdcfgigcjhabgbe","aihebchihaj","ajg","bcbfjdhggiejiegb","dcidcjfjbjdeaaaa","adjfafdiidhbd","agcgc","ibadbjaibbfedeihc","f","dfhbfc","cafcabf","jagabhccb","gihjgdghheecccjh","dcgagidcc","eagbacfbhhdfhbdee","ciabd","bffhffji","afhdacaieggchbe","dijccbdahfabdc","ffeggc","aghgadjjgj","bjadiibjedid","bgcghaheei","icaiaehegbj","ghjadjihcfded","ej","gfgdhiajhd","ede","ggg","hjjdehhja","bagif","fcfdgfcfbjjfeffia","c","bdcejcacbghgahcafe","ejhbfijefb","dfhjhegeafjcigbbia","fgdffacbejajic","chcfgfgjcbiehicfd","ejahbjbcbicjagachj","a","egbgfibdahjadafcgd","gjfbjjbaidhiehafegfd","hfaaeiceefbhcgea","bhhfdf","gbdfjjaccdfcbhhhehf","ejeeeaac","abajajb","ehdcijage","fbigaeifehc","bdghgdi","jhafgbjfieaijgbej","fehehbgabdhhgadhadbg","jaighehajjhcecbjc","adjdbidf","jbfahhihjg","hbbgdi","gcjcggfhdihfb","heigdhji","ahabiaeie","hhedjbaha","bfhjjhbb","ijhdfiafhhehjghgfi","dcgedjgaeffhajhag","g","jhjceaaaifafdggfjbg","ghbdcbjhgeeehhcbf","ffgfceejhec","ifabh","hhihcfbbhe","cdhdgjgcdd","cchcebbggjjffiihdccg","iifbgh","ff","jjehcheh","bciehbbcjgjb","h","hehgfiiejecfjiheedi","aijij","bifghcabigi","gejfccgdfibehjjb","gcjjbffgiag","cadagdeh","hhhgfeddfdfh","dffihfiabfadgeiiedfd","cheeieejejeibe","ceijced","dhbfhhfha","iicacg","eadcjfcfjgdeegihb","cfadjcagje","gi","eiafffehbicih","babdjgc","didhdifig","jfhcdig","cddhh","ffihbbb","ajfeacghfbghgjhbgf","bcbgaejjgih","jhbgbi","cichadjabgec","gahfjibcbijehejbeja","ffac","aajdaafabeicbgggch","fcgcajcfhfjhbhhbdja","fbaieaggbdfhcbgg","iggaec","afd","dgbiejffcihhhh","ddaihgadjajhgecghb","gfdcije","gjeeaibgdeeiiehfag","afhhdjciadbhfijia","dbjd","hgcahhh","cadjbjibjjgfecedd","hhedh","d","bbhccjahdjhde","cghecigajdfcebaj","hbefgj","ijdchhbg","jgfcdfbgjbjaadeji","jibedfieeeaddfcc","geaggid","heicfjja","dhffajiibegj","bebjbfijhggef","jgfffhe","iciehbgcdaj","bhgdjfchhfbhcc","hbdfhffjibjiejeehdia","fcfhihdjefbif","ddfhejhcaecigbicjcfb","cgdaj","iejeiccd","gcdgibedjagiajgccjj","cf","ddgeeajaiafaaah","eafjajgaj","fiidfdgdfegdejfch","hcadjhaeddgegheachae","jffjhjhhbdciid","ijhhfgjafafgc","feejjjjicfiej","gifbfhjedibgc","heihahagfbgi","ha","gafjiebffdjeda","di","debbffaafhejbiegbbgb","ibiai","aibacbhadedihjghia","hdjeeijejbjdbhjje","jiabhdafhbhgcfcgbgcc","dgibabc","fjhcbejhddid","fgbaa","bdbecijb","gdjigbhf","gdacf","ijgaggafgciibgegeab","dgbij","ieaihec","bicfcbijd","dfcjbchda","badhh","fbacffdeejeeieidci","hf","afajihhdbjfaehgbiic","jhj","ieadbjbajhf","aaggiaggbd","ajiihgid","jacceifhihafcejbgdfj","agg","bchebejff","ffafgifbjaifcdcjac","bfhcdac","ciaccdgaaddhdddggajc","ficbgicjdigdb","j","iiaccjfdgheada","ahhiaabhjjgcfiffh","dafgcbhddecbcaificb","igiegagid","fcicgbecchfcbfh","hd","ecd","eibgdahagj","fagb","gaia","fhfhedcideejfh","fcjfdhfdhjcb","i","gfahba","bhbfeh","iicfddifedf","hajdh","ibjabeebabjeebadid","gcade","fcgiebibcee","fidbcfcbj","jjbefffgb","jdhicajehjjieaffah","hieacaehedcfjhd","ajbhehbbedabgd","dgaaffaaddcac","hcihiddcacigbihdde","fgfbbgjcfccdigiifg","fbbgcafhjchgege","fehdebe","cjbef","edeech","iacfgjgb","bfhbfajbgjghghefjfe","ajcab","hahadbhgaaijihdg","bbbfj","acddcaaa","jjffjg","daffibbgbgd","gif","adfajecefibjgfijia","ecfjdhbg","icjgghdggaccjfca","cbijbdda","ebcgefg","hhdihbdech","giecihcfheigadacccej","dfdihbdecicih","acgfjahdggaedj","idbfcbjheaeejbhgh","eg","fccccacfj","bdeejfgjegedjfi","eeecjchfd","fgcbacjajgjhcicedhb","ggihffdhcjdhceihefeb","hb","fejcdgjecgbgad","efedbfefdjcdbdbf","idggadbhcgc","eecgbggicdfgdchdc","jfebg","eiajhcjgcgcbiijcdbd","ddbabbdiejea","afijhecebeaicjdbh","egfggicgafdfjffchc","ibe","ebgafcabicdadfcf","gccgdd","df","bh","fjhcfidjcfjjf","dgabf","iegdi","hhajdhhfbcb","hifiagahhjdajaffg","diaieigfbjbi","igadhdccbagdbdhb","afbebcg","hdbabgcb","bajhfcaffd","hihajh","ihddehfdbbfdhijajj","ddhhebifhdbhehi","agchhgf","dfddhfb","iecdi","fbdaeicec","gacbfijideifjeci","igefbebaajjb","ae","efj","gd","ehighddgheigbba","cdgjhdhhhig","fbeaj","icjdcchd","decbbeiace","dbgeaebcdifcgje","fecahfbjge","gecaibhgefchabhjba","cfbhe","ijhhabghjhaihgchhijh","eaebiaa","djjdjcjjbijece","aeajjcdiecajci","hhgcgidjedhceee","jjihccjicggedefdja","ggfedgfc","gbecdg","fagjaiicgaeaajdbic","eciifeejadicdfif","edfcjffaj","cjjabfddiaeeccch","fdcfeffgjj","ffdgfg","fbccfcgi","acjjb","efjijdhfdbh","hajiccffdcjibcdb","bgfdag","bajaggbbhjb","bfaijdfgiibfd","ggdc","cebeajibb","hfajea","e","gegjfge","ffhcf","chbcfejidifffcfhdafd","ffdhjagage","bccj","aggf","caddgheabfiebg","jaefdiajfgg","ghjacdjgbieddcc","aifhhdbbfbhebcdhgeab","fci","figfjibfefgdhjfgd","efibdccbicafggd","b","ddicbcaaijehcjfg","hdffieaaaijbbcigfhfe","ajead","dhhif","ajbf","jgcja","jibgajaiecfhhbgdceg","ccibagddg","hgidf","adfgedjgcdgiadajj","ijebjcbic","ciefheifgbeicdgibj","dgahi","fhjbgbb","hffejjdae","jacgigg","bahigaghgddabiagdij","gfeabiehidfcfcfffgea","gcca","gjjhhcejf","hfcbeacdfbdeeajgji","jghjcigggjiafaieg","ccdfbdbeef","iacd","dgfbhfbcbbgj","hcedhff","acbhggebigbcifibdjdc","dijadjjagjcgadfgabcj","jabadhi","dfagbfcbabbcciif","cfdebjhggbjhafhc","be","jieidigcehibbjhhedcc","diifieegbhbb","ddiaiiieiccd","bfca","bbjcdgeecdhigii","idjeice","jaagfbjgdjd","gjfffchggbide","ab","ddjcgdihdegfea","chdacahjheca","ihbcjeci","ei","ihggjiacddjcfej","jgjdgd","ceeeeb","eddhcj","afbffebghffhcbh","ajahbdbj","cdfeeffhida","jabeebj","jehheci","ahj","hhccigjeaaahbhei","gjhgijdb","achfdjhjdfa","ihadicdiehbfiib","gghf","ecghj","fcccfibhcdeidhdacedj","ebjdfadejcefcbafjbc","ifbcjghiafieadgj","igcahjccggagifdagci","gfgjhejggeebaicjhed","djdcca","gedddfjgcg","gjhcihgcjaigg","bci","bbajhdbegfff","efhdieahidccjbcfdg","bgaffaaffaahhiae","jdf","cacijjegcchbefjgegej","hceiacffdacegfadgdha","afcjfabgcfhcee","bgffafaii","bjcediebcfafjj","gbbdjcbhagbihgicdece","jgf","jcccigaiccb","ci","hfgbaagdcbc","eeddjcebbceechigbc","ai","ficjadcjcecdceaj","abibehhaghgdibbfdgf","bjhdbfiadbhhijha","ghfeiibagfafgag","idbcbhgggbfadbca","ddjf","aaedgijeacgigjcb","gfffcggdeagc","aigcejdddcjjcijhg","jidhf","ccjfiacjga","cfbgehdiijefghdi","cjhggijefc","ghefchcghdi","ggdgcg","cfcgcg","gejcg","hda","iiahbacjgcjeche","hggcdedcbaaa","edhffjjciefgaggjh","bdijbjecahccj","cghjf","heghfhbbcieefeihea","ecegbdhdiccfafjb","fefe","bjag","beiachiddeejjebaffc","abbeijcae","fibfgibgejge","hgiaeeabbjicbgcjacgh","dfehgedhibjegihg","cei","dbifdigijbhffcb","jdifecjeaech","ageaced","gjdgjijahd","afagejhighhjc","jgdedeeddifh","chgejdbgdfh","jcaiaacjfbe","gbbhehg","cgabjdf","idabcffjeca","hcigiiighaagfibcdee","gicjfefghjhgjbej","aiicbaibbhgij","gfjjgahcdhcfjgjh","dajjjcgjbjjhhjgede","gbihffaehafijb","jddiccefhiiaag","icbjgbjcddh","jheahdigdhba","egiagdbgcchceiigj","gdfjcj","jj","hejjgjdjafh","cbbahdiacf","jbdgggagfbhaea","hbghcjbg","bifbcdjhcjdgab","jgcfcdcgjf","gcechagbjjgig","ajfhcbg","fgdhbicahciibggi","gbgdgee","biebhj","gcbccegffdae","djihcai","ibb","acbdahhcac","hicggfibahcjjddbd","abcbbihcfijh","icfhhhejf","ahcajdabi","haifac","fhaabcebgcfgjhi","bjhegacjid","hi","ebbeifgfjbecgigbfbj","chjj","eihid","abagicda","cjdhdjcegifge","gdfebb","eehifdhcbfcgjcf","dfgihajihcfgggfgj","dfj","gcgjaejffacedeefadj","bbihahhd","cacfagiehijbfhh","jahdhbjgghjhbbcdc","bdaci","agbhjiddjibbbhi","iaahfjahijgehedehga","hba","hcaede","acebdibb","cidjeej","fjfaagbdhj","jgiijidfdhccdgaf","hebdh","hc","dgc","eihfdgfcfegjh","cifafgchef","dcjjaejbbhcg","ed","dchbadiijcgdgfhc","iachcahh","bbfdcbgebjdcgjdecjc","ieaahbbghbhcceiiih","ehcefbdjhaa","gfcebeaag","aagaciebjc","ddcj","ihiiffcjihjf","jg","iadefabbbi","abeecfbggefadj","hcegihihffefjfd","gg","adcjig","jcecbjgdabgf","hidiehjcfi","bagfgeidddaeg","idcfajfhbecdiffddjgi","jehejjiffejc","dffbicgbcg","jeechjjeicdhjhgbfbc","ihegffffddibgjaihb","giaji","ibffjff","aehigjjihjcjaaecaa","cfbbfhdiedfca","ffjgcfhbdgjjfibhcgbg","jcjeacdhfaejgjh","dehijfcc","iab","jfedijhadd","ddacabdggffeafhf","haefgjcghjb","ciiijbjcjggafffcbdh","gbejgbca","ejbcdbgdiij","cghgigjccgihdaadad","baibfhajibbgai","djigeegfhgjdbii","behgiggfbggagbjjead","hbafajbcegfagjfie","bjgadiehieaabjechad","hhahiefdddagii","fgai","gbghejhicfhgbfdd","igejcfiehdbedib","jhbcbheeghche","fahbjf","bhddiac","hbhgahbchia","bcgiajghhadjbi","fcecjebeeed","jffhfeebaehj","bdfgadjhibhdfe","aihaddcag","gadjh","hjfgbcjefchei","aeaeiiggdecjci","jdacdhacdf","fjibahfad","ghfhhjbi","jdadabecgjgdd","fdhjhcjafdddfbfddd","eebfecj","caejfacaj","ifjafd","ibjijg","difgbcbagd","bhdccjagda","hdaagjciddhidahaj","jciaaifajdbdigjahi","giiaed","hchg","jchigeafchcjihbhgfdh","cefibahdbdhdcdehhach","ecgd","iecfiagbehcbfieb","bfjbejaijcbdacdgebb","ghhedhgfgidbcghfbii","cgej","ijaibfjdh","jifid","ahaijbcahihaggfjb","cggjeeffjihiiegdgj","ececf","fdja","hgiajfjccahbf","edhhadhjcjf","aga","gibcgibbeiaadji","jfgbdccaceghed","dei","icgfdedd","iijegfhabaiaejfg","fbaj","jchcaeaegjefbbgdcj","hhjfdahegacbagcdehf","ibjd","jgbcajgbeeeee","gaheddaade","biheih","bichfdeiggebhdbeiii","giedafeadagehfbchg","ibbjaehhgccjbajg","hejfgfg","fcfadhbchbbafjicfia","ajegfdc","hffdecgdij","fgec","gcjdcgaibhfae","fahdcbfje","dbabdijahcfh","hhhjc","hjcfgjcjihfjac","cdhgaiffedf","ehjaeighajde","ficafaejah","fbeca","afecbj","jcd","accc","jibdbgaiiddbha","jahcbjhh","ehbfcjdhgbaabecfch","jjej","fbaccjcicjfg","gicjcdb","fafiedg","eggbiffacjabce","gjihijfaccg","ddjhgaacfdfaeiec","ddgbcbgh","bjheac","jfjjjcdiia","jcahdiadggahigeb","fhbdheeb","bbeeaiejcijceb","fg","dijd","jcbifefjafdbcecidf","igjdff","bii","jhadci","jfgafeb","jifdjafbhcahhgbdeaaf","ceefe","hjeiebejegdcebig","igcaah","efecjciecjfdfaj","iecchica","ghccagabfcb","begjcd","bjgbffajjfhebjjfijad","bcfcbfdabgcbhjj","bif","ajaheccibiiefcjbge","dgf","jbda","ieebjjhfddd","bhabdhjagihidc","hhhcbjebajgcj","dggjdafgb","jeddiddec","jaac","igichgciaiaejae","eej","adib","ghih","bacgdcagdgbg","adibdjaijcdaeiehbihj","hedjedijdiiihc","ihhd","cccahffddabbfge","fdebcb","gfbejgce","eahgedeeijdeebdh","ddhjahccdebicijacbab","gaiddj","dacfjdjhcjbdbbehaa","dcecgda","cajiaj","bjdideadicfhceheb","cabdjdgfcaeedjgef","cefaaagacdachb","cdeefbaifdhjijb","iehdejdeeejb","ggedij","gchacfdgcaje","jhjcibgjaijeha","diecfiaghagcha","daebehehfccgjcbhh","gdfbgag","cd","gddeffieffaefhijd","hcf","gihj","gicaehjec","gegfegiegdj","ijeihj","degje","gjigeiaa","cjhecbedhjbadbcbbbic","eciacehfadje","eebajeicfacgecddffce","ehgj","dhbccefceh","djedfbbfjbaje","abdbeaf","dehg","ig","caadabchdgibf","ad","ebhbjfhjfdhahddfgg","abcajbih","iceaffifhjgcfb","ffgaibdbhaaaeid","fbchgeihhahc","iaieajgab","jfijfjgbagjajhebc","gfhgaefjeaiiecghhagc","jhiaii","cgid","jgfgabagdjhfic","bcfibaeaaejbeghahdi","jaiihgeehbdceb","acidcfdh","cb","hhgdigdg","edfbdd","efdgegdeaeebjji","ccee","cbiadgbhahdifahc","ehdfbj","ejdcceiijiijf","efdjhi","ebgefdgfebidf","aaddehhaa","dgi","ehfbg","cicdecehhigjej","febcieagic","feffd","iiigddfegfggdafg","jch","fc","diddgccdhbeiaibdfb","hbbfecfdaih","fdegfh","aecjc","fgbebchgegfjahbbh","dhigah","ccdbeeabdif","aagg","didedhbcgbgjdbijfi","bihfbcbi","fjbiiabcaiciebfeeije","haefhdjbjafjdce","decgcfecbficieaija","bfgbia","hjgaidedej","daecbjhhghehbgagg","jic","caaih","ccbahijhdebdagcd","idcia","ebiafdbaagdfceaeh","icai","ddiddhaecdhbegiae","ggeggjefb","bieef","dbhiajdg","dijiicdcaecfahaghifh","hffej","bjicafedhie","bafaifaecdg","jeggaib","idefjigbhgggbehechdc","baaejhajhecfgh","bcbbbbcfiahihdigjh","bjgibahac","hhfgfchjdhd","idhigfhicbjdaahd","hbaccjb","hci","bfcfabgieahge","fejjgjehcfg","fdbcjfcdddcbgg","fj","ieefdchjddbjied","cgbcef","bjiaefaeacdeedidec","cjjjjheffeedi","eacbihacdghejb","hibfjbchjifhjehf","bhj","ddhigieieihc","ahdcdfjbbciijegbieh","hjifdabfcghefcagacdj","cdgejiia","efbbgdhce","fbcid","jc","ajggijeiehefihjfjcb","hfhbbcehbf","gdfejbf","dbbgigbgiigjaddbe","bbf","cfegjag","igcdiaefdcigeefb","adcea","ifbiffjhjbdb","ghba","bdfedag","gjhjbadcgh","djdcd","efbhdjhbgicfhg","jicggbdcjag","gdd","gfibdbdhja","fddeabcf","ifcffchfafigd","fieaj","dhac","jehieab","eiea","jaiiddehfecgbacjh","bjhdjcggcajcbjde","beeeeidcccfgheda","ajgehbggjcabjb","ie","ibaadgbddjaigedgj","jedf","difdjgd","faciicicciig","chafeahhi","iafhbdjjhgajcf","geh","dcgacbhdhddghd","afefahjbhigijaidhfa","cbdijeeaaag","ec","bbb","gafgabhbhejfib","iaihfebdjch","ifdbcjg","jaddcae","he","ac","gjajcgddaja","hee","bcce","abfjg","hchbeb","egeajedhh","gcbdchec","ggjdihjiibgafja","bhaeagf","bfajgcdcgahe","iceiidhjgjaaibeceg","eigefc"};
    cout << Solution().palindromePairs(words) << endl;
    clock_t end = clock();
    cout << "Time used: " << end - start << endl;
    return 0;
}
