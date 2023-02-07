#include <gtest/gtest.h>
#include "BigInteger.h"

// COPY

TEST(copy, test1) {
    BigInteger A("");
    BigInteger B = A;
    ASSERT_EQ(A, B);
}

TEST(copy, test2) {
    BigInteger A("abc1234567887654321");
    BigInteger B = A;
    ASSERT_EQ(A, B);
}

TEST(copy, test3) {
    BigInteger A("abcdef");
    BigInteger B = A;
    ASSERT_EQ(A, B);
}

TEST(copy, test4) {
    BigInteger A("112233445566778899aabbccddeeff00");
    BigInteger B = A;
    ASSERT_EQ(A, B);
}

// ASSIGNMENT

TEST(assignment, test1) {
    BigInteger A(""), B("");
    A = B;
    ASSERT_EQ(A, B);
}

TEST(assignment, test2) {
    BigInteger A("abc1234567887654321"), B("abc1234567887654321");
    A = B;
    ASSERT_EQ(A, B);
}

TEST(assignment, test3) {
    BigInteger A(""), B("112233445566778899aabbccddeeff00");
    A = B;
    ASSERT_EQ(A, B);
}

TEST(assignment, test4) {
    BigInteger A("abcdef"), B("");
    A = B;
    ASSERT_EQ(A, B);
}

TEST(assignment, test5) {
    BigInteger A("112233445566778899aabbccddeeff00"), B("abc1234567887654321");
    A = B;
    ASSERT_EQ(A, B);
}

// EQUAL

TEST(equal, test1) {
    BigInteger A(""), B("");
    ASSERT_TRUE(A == B);
}

TEST(equal, test2) {
    BigInteger A("abc1234567887654321"), B("abc1234567887654321");
    ASSERT_TRUE(A == B);
}

TEST(equal, test3) {
    BigInteger A("112233445566778899aabbccddeeff00"), B("112233445566778899aabbccddeeff00");
    ASSERT_TRUE(A == B);
}

TEST(equal, test4) {
    BigInteger A("abcdef"), B("abcdef");
    ASSERT_TRUE(A == B);
}

TEST(equal, test5) {
    BigInteger A(""), B("112233445566778899aabbccddeeff00");
    ASSERT_FALSE(A == B);
}

TEST(equal, test6) {
    BigInteger A("abcdef"), B("");
    ASSERT_FALSE(A == B);
}

TEST(equal, test7) {
    BigInteger A("112233445566778899aabbccddeeff00"), B("abc1234567887654321");
    ASSERT_FALSE(A == B);
}

TEST(equal, test8) {
    BigInteger A("abc1234567887654321"), B("abcdef");
    ASSERT_FALSE(A == B);
}

// OUTPUT

TEST(output, test1) {
    BigInteger A("");
    std::stringstream sstream;
    sstream << A;
    ASSERT_EQ(sstream.str(), "0");
}

TEST(output, test2) {
    std::string str("abc1234567887654321");
    BigInteger A(str);
    std::stringstream sstream;
    sstream << A;
    ASSERT_EQ(sstream.str(), str);
}

TEST(output, test3) {
    std::string str("abcdef");
    BigInteger A(str);
    std::stringstream sstream;
    sstream << A;
    ASSERT_EQ(sstream.str(), str);
}

TEST(output, test4) {
    std::string str("112233445566778899aabbccddeeff00");
    BigInteger A(str);
    std::stringstream sstream;
    sstream << A;
    ASSERT_EQ(sstream.str(), str);
}

// ADD

TEST(add, test1) {
    BigInteger A(""), B("");
    ASSERT_EQ(A + B, BigInteger(""));
}

TEST(add, test2) {
    BigInteger A(""), B("abc1234567887654321");
    ASSERT_EQ(A + B, BigInteger("abc1234567887654321"));
}

TEST(add, test3) {
    BigInteger A("d99e33a3ee041b4fbd5d83b1ddbdf9bb"), B("1c48c0891137f43dde4e");
    ASSERT_EQ(A + B, BigInteger("d99e33a3ee0437987de694e9d1fbd809"));
}

TEST(add, test4) {
    BigInteger A("e4f32b8ff35d95722edb"), B("24e51ca3095303346dbd");
    ASSERT_EQ(A + B, BigInteger("109d84832fcb098a69c98"));
}

TEST(add, test5) {
    BigInteger A("10849a75486314dac2f8cbf4a3a42e1baa203ab52baeeb690b884f182331f6aa952302128dc9c23acfa719964ac3d5dd2b0354f45a1c82634f7e77bcfe6f09ff35c745903aaf868e256b95e305786be289c6b361d6ce946a3ec92b0cc4da65c171ffbd78c53b79045cb1e534be23b87d81ab478e7ff38c4504b4ad6a942dfaa2602bdd01a64b22b173d07e7af56d230ce5ffa3bf1992ecec9430f6b2180ad01e111fd4c48f219519796b6d0ecb3eed875ee77bc35ac2ecd8d4c0c0c0091d00b5ee7a98c400ad1de8eedb27501926bffce9c248f57a198b7caaf67e4ab45d948aa10d46261e1d57b18ef9153fc3ad07c731d5c6380bc9eacf99e79186a8ba6b81");
    BigInteger B("5f8ca91cc2f8ed3ccae95f317774c1482e0d9a523d40d6fa5b13770b212df28723467364bfa8014de28e808b1b0c740ee0087d7466894407179cbba6702b2c52c3ade461e1867d99d3c794d4677a7701bc1df9c613a4e61b0d8b44a808afd0179feb7a65b0b29e3dfa038b07cbbb5db931d193d1a1eebde21a9a2bae0fa5dce391df46662c8f5f70c1ba2bfdd948e32446203fdf3e61e5f66c5fc893899b839d2d112fcac4b83a6514db7aa234ee07ee20f37e684135837c7dbe9420169227d320eb766c181192807053fb84de5d5c54efdff2666ecdab0e24a9082d6a953be74c7cbf2f80be70f250cfde6aad2632cb61d6c59260f80bcb5a96ba31ca77ac71");
    BigInteger C("701143920b5c02178de22b261b18ef63d82dd50768efc263669bc623445fe931b86975774d71c388b2359a2165d049ec0b0bd268c0a5c66a671b33636e9a3651f97529f21c360427f9332ab76cf2e2e445e4ad27ea737a854c546fb4cd8a35d911eb37de75ee174256b5703c89df1636b37cdb6021e24a271f4ed918a3d3d785f20b2367d2da8222358aaa78ceb606312c1fe39e57f4d2e30090bf45a1a653bb3e31048f53d9cf7e8e46e7b1002cf5757fdafa2b9bf87055527f54e01faf28890f660f3018beb0695f2f22d4f7841c51d9a23b5be8e7368acf9f86781ef2d071ed8a05559edbc8a3dfc8f3aa70d33a9293ac8bca6cc1f69af47e4bb8733217f2");
    ASSERT_EQ(A + B, C);
}

TEST(add, test6) {
    BigInteger A("10849a75486314dac2f8cbf4a3a42e1baa203ab52baeeb690b884f182331f6aa952302128dc9c23acfa719964ac3d5dd2b0354f45a1c82634f7e77bcfe6f09ff35c745903aaf868e256b95e305786be289c6b361d6ce946a3ec92b0cc4da65c171ffbd78c53b79045cb1e534be23b87d81ab478e7ff38c4504b4ad6a942dfaa2602bdd01a64b22b173d07e7af56d230ce5ffa3bf1992ecec9430f6b2180ad01e111fd4c48f219519796b6d0ecb3eed875ee77bc35ac2ecd8d4c0c0c0091d00b5ee7a98c400ad1de8eedb27501926bffce9c248f57a198b7caaf67e4ab45d948aa10d46261e1d57b18ef9153fc3ad07c731d5c6380bc9eacf99e79186a8ba6b81");
    BigInteger B("14e8bfe26838634d23a464a4113f341bf6a00f067742a545271bcf4bf6195928fa70a7f596078f868d209968eb268bf9b8409d8201807f9042ac6a30fe4271e2d7e48f9a0835eacd363f514403fd21f5dd4cc5825ea5600b76c984f1b1ddd71cbf0c92ede96dc52d4ffd7819880b4cc2dfeab48a62528bcb5f1dd44811ff32dd");
    BigInteger C("10849a75486314dac2f8cbf4a3a42e1baa203ab52baeeb690b884f182331f6aa952302128dc9c23acfa719964ac3d5dd2b0354f45a1c82634f7e77bcfe6f09ff35c745903aaf868e256b95e305786be289c6b361d6ce946a3ec92b0cc4da65c171ffbd78c53b79045cb1e534be23b87d81ab478e7ff38c4504b4ad6a942dfaa275149ce40e8385fe9774e31f06ac5728dc9fb2c590d59231bb4cc5fe0e2429470b907cba252924a0068c0677b6657981172819455c436c69176d2af1075f7298c65f285e08e308b6251a78941d23e1f2c70f0e77d8beeb8821c0033c663b6ba76019d914078b1cdedef68d594bb8548a11c07ac26e1c769af90565cebab99e5e");
    ASSERT_EQ(A + B, C);
}

TEST(add, test7) {
    BigInteger A("f888888888888888"), B("a777777777777777");
    ASSERT_EQ(A + B, BigInteger("19fffffffffffffff"));
}

TEST(add, test8) {
    BigInteger A("f88888888888888"), B("a77777777777777");
    ASSERT_EQ(A + B, BigInteger("19ffffffffffffff"));
}

// SUB
//todo: make normal tests especially for subtraction

TEST(sub, test1) {
    BigInteger A(""), B("");
    ASSERT_EQ(A - B, BigInteger(""));
}

TEST(sub, test2) {
    BigInteger A(""), B("abc1234567887654321");
    ASSERT_EQ(A - B, BigInteger(""));
}

TEST(sub, test3) {
    BigInteger A("d99e33a3ee041b4fbd5d83b1ddbdf9bb"), B("1c48c0891137f43dde4e");
    ASSERT_EQ(A - B, BigInteger("d99e33a3ee03ff06fcd47279e9801b6d"));
}

TEST(sub, test4) {
    BigInteger A("e4f32b8ff35d95722edb"), B("24e51ca3095303346dbd");
    ASSERT_EQ(A - B, BigInteger("c00e0eecea0a923dc11e"));
}

TEST(sub, test5) {
    BigInteger A("5f8ca91cc2f8ed3ccae95f317774c1482e0d9a523d40d6fa5b13770b212df28723467364bfa8014de28e808b1b0c740ee0087d7466894407179cbba6702b2c52c3ade461e1867d99d3c794d4677a7701bc1df9c613a4e61b0d8b44a808afd0179feb7a65b0b29e3dfa038b07cbbb5db931d193d1a1eebde21a9a2bae0fa5dce391df46662c8f5f70c1ba2bfdd948e32446203fdf3e61e5f66c5fc893899b839d2d112fcac4b83a6514db7aa234ee07ee20f37e684135837c7dbe9420169227d320eb766c181192807053fb84de5d5c54efdff2666ecdab0e24a9082d6a953be74c7cbf2f80be70f250cfde6aad2632cb61d6c59260f80bcb5a96ba31ca77ac71");
    BigInteger B("10849a75486314dac2f8cbf4a3a42e1baa203ab52baeeb690b884f182331f6aa952302128dc9c23acfa719964ac3d5dd2b0354f45a1c82634f7e77bcfe6f09ff35c745903aaf868e256b95e305786be289c6b361d6ce946a3ec92b0cc4da65c171ffbd78c53b79045cb1e534be23b87d81ab478e7ff38c4504b4ad6a942dfaa2602bdd01a64b22b173d07e7af56d230ce5ffa3bf1992ecec9430f6b2180ad01e111fd4c48f219519796b6d0ecb3eed875ee77bc35ac2ecd8d4c0c0c0091d00b5ee7a98c400ad1de8eedb27501926bffce9c248f57a198b7caaf67e4ab45d948aa10d46261e1d57b18ef9153fc3ad07c731d5c6380bc9eacf99e79186a8ba6b81");
    BigInteger C("4f080ea77a95d86207f0933cd3d0932c83ed5f9d1191eb914f8b27f2fdfbfbdc8e23715231de3f1312e766f4d0489e31b50528800c6cc1a3c81e43e971bc22538de69ed1a6d6f70bae5bfef162020b1f325746643cd651b0cec2199b43d56a562debbceceb7725399d51a5d30d97a53bb0264c4321fb319d15e57e437b77e24131b3696486443cbf4de9ad82e3dbc01760209c2024cef909d82ed1e17190b37f1bf15b063596a54b9b700d9369af1a66c20c02a4e67296a3a8fdd3600d75271d3270dda8176474978178d434c5369c58061da970f4b41f9179b289e2b637a75cab6f790962a11940c1d6c92ae9792b043000ff5a552e20fbc0af28ab21bd40f0");
    ASSERT_EQ(A - B, C);
}

TEST(sub, test6) {
    BigInteger A("10849a75486314dac2f8cbf4a3a42e1baa203ab52baeeb690b884f182331f6aa952302128dc9c23acfa719964ac3d5dd2b0354f45a1c82634f7e77bcfe6f09ff35c745903aaf868e256b95e305786be289c6b361d6ce946a3ec92b0cc4da65c171ffbd78c53b79045cb1e534be23b87d81ab478e7ff38c4504b4ad6a942dfaa2602bdd01a64b22b173d07e7af56d230ce5ffa3bf1992ecec9430f6b2180ad01e111fd4c48f219519796b6d0ecb3eed875ee77bc35ac2ecd8d4c0c0c0091d00b5ee7a98c400ad1de8eedb27501926bffce9c248f57a198b7caaf67e4ab45d948aa10d46261e1d57b18ef9153fc3ad07c731d5c6380bc9eacf99e79186a8ba6b81");
    BigInteger B("14e8bfe26838634d23a464a4113f341bf6a00f067742a545271bcf4bf6195928fa70a7f596078f868d209968eb268bf9b8409d8201807f9042ac6a30fe4271e2d7e48f9a0835eacd363f514403fd21f5dd4cc5825ea5600b76c984f1b1ddd71cbf0c92ede96dc52d4ffd7819880b4cc2dfeab48a62528bcb5f1dd44811ff32dd");
    BigInteger C("10849a75486314dac2f8cbf4a3a42e1baa203ab52baeeb690b884f182331f6aa952302128dc9c23acfa719964ac3d5dd2b0354f45a1c82634f7e77bcfe6f09ff35c745903aaf868e256b95e305786be289c6b361d6ce946a3ec92b0cc4da65c171ffbd78c53b79045cb1e534be23b87d81ab478e7ff38c4504b4ad6a942dfaa24b431d1f3e12bf64502c19d6e42deef0ef5f94b8a25047a76d15276621f176f516af2ccef91a0592ec4ad3a5e018618da6a6de4159426d489214568f0ada8ed316960929f877331bb89bd60c15299e070c7583731b742b71342cf959027fbd6de200b33834af92843efb9d263ba1bb0451eb11ada9775f043ac9bd3e96bb38a4");
    ASSERT_EQ(A - B, C);
}

TEST(sub, test7) {
    BigInteger A("f888888888888888"), B("a777777777777777");
    ASSERT_EQ(A - B, BigInteger("5111111111111111"));
}

TEST(sub, test8) {
    BigInteger A("f88888888888888"), B("a77777777777777");
    ASSERT_EQ(A - B, BigInteger("511111111111111"));
}

// MUL

TEST(mul, test1) {
    BigInteger A("2");
    BigInteger B("2");
    BigInteger C("4");
    ASSERT_EQ(A * B, C);
}

TEST(mul, test2) {
    BigInteger A("8b0182de0f8768d2401dd94fc2d769e1");
    BigInteger B("c10dabebb33b71276f7929b01609f039");
    BigInteger C("68d390170d1bab6a0be51575435798a1ac34d04bcf3c62b0cf5359c864228319");
    ASSERT_EQ(A * B, C);
}

TEST(mul, test3) {
    BigInteger A("d7f6bcf0b90661ca904ac4f75af64a9c9e11d6f56523f7c0afb776429e88f36dcd33c0589e66e3c80cccafb52491ed1f9bed29649b72509be1434a84eecf61d9dbee808fb71b88e62fb6d919bf50b562236083eb8561ea0fdfe06dd83f44a4b25ac851a7cd3f53e0065f582708767a2b8d90af24d44281d0fdf46390b009ae10dbbad55da3c3eb0d965c6e1dabb2635489c6811219dc1b1783fc5f5edb590b989e0f99307da4e23b302021e7665f0257a718b7e3442adc4e171a5d0054ca3d5ccc8b206c03dca09d544cab473704947078fd72a3913760eb51731de3fb0fbe768bfb3a99fd5d690546f9bd7ac613322a3c839fea31129145359fa867c3ec1360");
    BigInteger B("dee6b883aa2261c7f8dc176e05a9bd7eb7f758620e23190401cfd08e2304d9733396ded24d17aebed59d41d9e78b6d61115a836741e75fbaaf108c4fdecdb36b71a12be0338239ef12f9a05a183645321423d11d4bd430ed5c682dcdb7a6dcdc1ec28cd56aafb3e5646e3047750197d0fed5ba31a5518c806888b0c2fbc87962fda13670d595137afe1f82d66aa3a4e16e72c421b1c443f35a5bc4a586b5d34d3bee5fce4b0dc2de8f71f7e5220c54fc6109782b82abe3e1722b2de8a056ad01b02ab7302c9c0a45f2768b914f797a6137071136807e9aebd19fb7e6268c3d2cbebbcf7bda0f88770277c41e8af32c5f47aada0233422c9866c76b22aa2e0cbc");
    BigInteger C("bc0a9b2eeb50536eecd7b43558917b832d806228668ce60038196e00ab7dd05bcb558ea28e7f115a7a79caa76722be66d815bb0a82387569c3fd43b9955e4abc3ac0d4c176b784e314d2c678be7f8f352db304a6ab7cbcfa884c076fffdec4bdc2d548e0f0f6c52d81369e08aaa61593f2ac93ea97e2b0fc33fb270ebfcf6a037b2fa357aa4d115d2610279743b2489a990b0512009320d518765e1a7088441a087092d6af0a03e6bf98aa338555c966f8abaf91f937b0116b2a82e7dac7ab95dd79f8e9368eac6d08360118549401aa46b0d9554924343f87476fb397da6c95a60ce44aa7d3e56ebbe147a31e1462b3cc3ebf423a5e1733390661de23962db0749f9717087f5b9d54fe53773eb1f17d8f1e8531c7c868c41e8f76b44cac6e65b5ea6929c3e4fb177c8edf9428d32d63f142fee46483a95762b85c752d28764a21fc83da5b0fd64dee865e6f510afd3e821d7fc035ebf60d24a08e119c0583d97cb0423168cbdb3efaf888fb0f81df52dfb0b50bd4547dc5478bd550aa792bdde0b417a19b6407c90e04862197bbe6dcd556552b908cf4d61611edeb223a7a152de21c8aea989572c34192b8ff97572c6759e0cbf67ceecc772ff71996d7de3f424779c22288600d5a75682bf42467a49445396e268ec34ebbb2c58949e9f244a56669bc63263a53723de341129f7f1110cb59a91a0eafc308f8356c2d86ba80");
    ASSERT_EQ(A * B, C);
}

TEST(mul, test4) {
    BigInteger A("aaaaaaaa");
    BigInteger B("aaaaaaaa");
    BigInteger C("71c71c70e38e38e4");
    ASSERT_EQ(A * B, C);
}

TEST(mul, test5) {
    BigInteger A("");
    BigInteger B("dee6b883aa2261c7f8dc176e05a9bd7eb7f758620e23190401cfd08e2304d9733396ded24d17aebed59d41d9e78b6d61115a836741e75fbaaf108c4fdecdb36b71a12be0338239ef12f9a05a183645321423d11d4bd430ed5c682dcdb7a6dcdc1ec28cd56aafb3e5646e3047750197d0fed5ba31a5518c806888b0c2fbc87962fda13670d595137afe1f82d66aa3a4e16e72c421b1c443f35a5bc4a586b5d34d3bee5fce4b0dc2de8f71f7e5220c54fc6109782b82abe3e1722b2de8a056ad01b02ab7302c9c0a45f2768b914f797a6137071136807e9aebd19fb7e6268c3d2cbebbcf7bda0f88770277c41e8af32c5f47aada0233422c9866c76b22aa2e0cbc");
    BigInteger C("");
    ASSERT_EQ(A * B, C);
}

// DIV

TEST(div, test1) {
    BigInteger A("37271ea7e44fe72e4ad27a49e9828b00");
    BigInteger B("3db7");
    BigInteger C("e4c7abbd604385ed58c97ace2a86");
    ASSERT_EQ(A / B, C);
}

TEST(div, test2) {
    BigInteger A("ffffffff");
    BigInteger B("2");
    BigInteger C("7fffffff");
    ASSERT_EQ(A / B, C);
}

TEST(div, test3) {
    BigInteger A("4");
    BigInteger B("2");
    BigInteger C("2");
    ASSERT_EQ(A / B, C);
}

TEST(div, test4) {
    BigInteger A("6cf0790dfbbd34a82e256d55013db825dea91d449fcd0168ddc4d38134ff71a9ec51c961c3707b41d6d1bad8a90993065094b9607af617954b3f2a05ab4fb90bd4d402c1af2c368aa2f71e4d36849a156da756eb93c0c2b475d6fcacdfaf828853966282c097038c1dfd2c06c6a91c4baeb9285c90ca445c46b0e744187e4e000f74738f49edf21c8efca8ebeb2d1acfcd394c9f73ef5f5340a223c345e7ef5ee9eabbcce101813127486c02dc365b5ae6c9fb5ec4fadd2801e4b875021c5e84c84e3f548c6abbc6a00a104857c21b96c82d74c3b69b4da521700ffa52e72a545d49f423bce8a8a2eb5da901cdd0ddfe7a10cad522a485a642eca02ad5d34512");
    BigInteger B("3e455828b7357f813ee6eab910210bbac4a6e1380e7a659f39740debd8562120d584bb216d318190a79f2e787e30dbd072028ae859d65dbad1de1d09f4f3167bf023c4ff7d2b48855f96975dbec870e936a052f40901a9929dc9df8b7b8e1f8c5484594d07c7d98f045480b594009e37ebae4d9a9462a8f0658496e06e535e043cc8e6deb95ca750ba2875b9d187b97757b0fbc069418ad14521fd3b61debcd7c13a5eec6d4221df767ada960207a0a49e559149cd30ee8efdf196c7ac55cfe0e23c88a94ecafa7a6ea17a9d3403b9cbf8b25078d3c4b76b5db507eae4a72aee2c5603f6fb54cf1af79de9e08fb375fdb71e1aec40033f625d536792e3a33693");
    BigInteger C("1");
    ASSERT_EQ(A / B, C);
}

TEST(div, test5) {
    BigInteger A("1225cdf0c48682b84c52f511bb678ac50f37ca9131dc1bd4fb770c36695c50059f871578a7cc988b1f021e9e3aae9b3c19185329482b9b3d66028bbf0b4387d7340b8ce125744f44bc1c7f3c756d530a3242d25b723ce5b443f485d73df3c73654c90d0df5afa2a9d363146bb211054a45de5d6c41affc28c8ae9e09dada3daec0e7f1be7203971b6d45eb17c8efdc4f4ae73834dfe4be63a5797d4a3aced4f1a97dfe2a33e0078b540208be875deccb8de22caf5dfad56f7927b913f09c610736d2c1fa05fdc12fbc5b844b2e4cfb43ee4c6c3153146cf333b8ca8ef4d9c83d461b20c19f97740e8f0f985321673247b669e800450a334b05edd14e0ede01f8");
    BigInteger B("fa603673fc06f13e36567345adaf575e");
    BigInteger C("128e29a8b49381be7ce46a0e5e98e2b44e3a9906069cf488b7bae66f60c17659ffe7bcb3a0f22583e2c79ee713c559e79441a2d2ff57f82f07f07a220c0876143f781a10deec86c70ce6569a64e3198ab9ec7850f20f56e44f067c82a3604d3d460f54954dafaa663ad72ccc7332996e781a43d70049b7d90f596ffa2cec5922de6d47f63eb8339daf3e24e80d29bb08bea1b078577626970a5b101c89efe4c4d630196da89a931d71aa659073809b7682242b5f38ae2628c9071e5bb9d5580c9c5ca67fe6b4b72522a8556eaf258e1c000b5512596675040d4bf4cd720462912999e0a78ebace2b4961696188360e3f");
    ASSERT_EQ(A / B, C);
}
