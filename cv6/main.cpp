#include <iostream>
#include <bits/stdc++.h>
#include <iostream>         //todo
#include <string>


std::map<std::string, std::vector<std::tuple<int, int>>> words;
std::string text= "\n"
                  "001:001 In the beginning God created the heaven and the earth.\n"
                  "\n"
                  "001:002 And the earth was without form, and void; and darkness was\n"
                  "        upon the face of the deep. And the Spirit of God moved upon\n"
                  "        the face of the waters.\n"
                  "\n"
                  "001:003 And God said, Let there be light: and there was light.\n"
                  "\n"
                  "001:004 And God saw the light, that it was good: and God divided the\n"
                  "        light from the darkness.\n"
                  "\n"
                  "001:005 And God called the light Day, and the darkness he called\n"
                  "        Night. And the evening and the morning were the first day.\n"
                  "\n"
                  "001:006 And God said, Let there be a firmament in the midst of the\n"
                  "        waters, and let it divide the waters from the waters.\n"
                  "\n"
                  "001:007 And God made the firmament, and divided the waters which were\n"
                  "        under the firmament from the waters which were above the\n"
                  "        firmament: and it was so.\n"
                  "\n"
                  "001:008 And God called the firmament Heaven. And the evening and the\n"
                  "        morning were the second day.\n"
                  "\n"
                  "001:009 And God said, Let the waters under the heaven be gathered\n"
                  "        together unto one place, and let the dry land appear: and it\n"
                  "        was so.\n"
                  "\n"
                  "001:010 And God called the dry land Earth; and the gathering together\n"
                  "        of the waters called he Seas: and God saw that it was good.\n"
                  "\n"
                  "001:011 And God said, Let the earth bring forth grass, the herb\n"
                  "        yielding seed, and the fruit tree yielding fruit after his\n"
                  "        kind, whose seed is in itself, upon the earth: and it was so.\n"
                  "\n"
                  "001:012 And the earth brought forth grass, and herb yielding seed\n"
                  "        after his kind, and the tree yielding fruit, whose seed was in\n"
                  "        itself, after his kind: and God saw that it was good.\n"
                  "\n"
                  "001:013 And the evening and the morning were the third day.\n"
                  "\n"
                  "001:014 And God said, Let there be lights in the firmament of the\n"
                  "        heaven to divide the day from the night; and let them be for\n"
                  "        signs, and for seasons, and for days, and years:\n"
                  "\n"
                  "001:015 And let them be for lights in the firmament of the heaven to\n"
                  "        give light upon the earth: and it was so.\n"
                  "\n"
                  "001:016 And God made two great lights; the greater light to rule the\n"
                  "        day, and the lesser light to rule the night: he made the stars\n"
                  "        also.\n"
                  "\n"
                  "001:017 And God set them in the firmament of the heaven to give light\n"
                  "        upon the earth,\n"
                  "\n"
                  "001:018 And to rule over the day and over the night, and to divide the\n"
                  "        light from the darkness: and God saw that it was good.\n"
                  "\n"
                  "001:019 And the evening and the morning were the fourth day.\n"
                  "\n"
                  "001:020 And God said, Let the waters bring forth abundantly the moving\n"
                  "        creature that hath life, and fowl that may fly above the earth\n"
                  "        in the open firmament of heaven.\n"
                  "\n"
                  "001:021 And God created great whales, and every living creature that\n"
                  "        moveth, which the waters brought forth abundantly, after their\n"
                  "        kind, and every winged fowl after his kind: and God saw that\n"
                  "        it was good.\n"
                  "\n"
                  "001:022 And God blessed them, saying, Be fruitful, and multiply, and\n"
                  "        fill the waters in the seas, and let fowl multiply in the\n"
                  "        earth.\n"
                  "\n"
                  "001:023 And the evening and the morning were the fifth day.\n"
                  "\n"
                  "001:024 And God said, Let the earth bring forth the living creature\n"
                  "        after his kind, cattle, and creeping thing, and beast of the\n"
                  "        earth after his kind: and it was so.\n"
                  "\n"
                  "001:025 And God made the beast of the earth after his kind, and cattle\n"
                  "        after their kind, and every thing that creepeth upon the earth\n"
                  "        after his kind: and God saw that it was good.\n"
                  "\n"
                  "001:026 And God said, Let us make man in our image, after our\n"
                  "        likeness: and let them have dominion over the fish of the sea,\n"
                  "        and over the fowl of the air, and over the cattle, and over\n"
                  "        all the earth, and over every creeping thing that creepeth\n"
                  "        upon the earth.\n"
                  "\n"
                  "001:027 So God created man in his own image, in the image of God\n"
                  "        created he him; male and female created he them.\n"
                  "\n"
                  "001:028 And God blessed them, and God said unto them, Be fruitful, and\n"
                  "        multiply, and replenish the earth, and subdue it: and have\n"
                  "        dominion over the fish of the sea, and over the fowl of the\n"
                  "        air, and over every living thing that moveth upon the earth.";


int main() {

    std::istringstream ss (text);
    std::string word;
    while(ss>>word){
        words[word]=
    }
    return 0;
}
