#include <gtest/gtest.h>
#include "BigInteger.h"

TEST(div, test1) {
    BigInteger A("0");
    BigInteger B("d91ac0455a6f7db3d34b39b6d725d62d8487e82a53063635526d6cd14a0ff17081ea20ce184347ccc81288c558186faebe22bcae4f840fa2b3457b7366dbca5a39f7ac6dc29f5fda23b20c1c4e78e9c1e5e7fc834741cc13988360e312655753da4a569b7a3d51c4d99ce3dd8cc3c0cab3562875f8baeda5b73f7c44687b0289b5f74775a9ac7813d7bc769e0115b4d583363e304868505422b9a55a0cd165922daedec741036aa7287d69666ad9ac7d4dbff9b9fc56625d9ad0a9a46d3d097654bdec2cb3a363f2f0ba37a68c523ed2a7847da9ed8162d7e4b359186491d7ac8af685889609c4eabfec951a780291a4ef87636ff5203a48a55484c92e79ac46");
    BigInteger C("0");
    ASSERT_EQ(A / B, C);
}

TEST(div, test2) {
    BigInteger A("3e680228da30bbc74b1effa364e3752aa9372bb9ef1f892e11b36497a1cdb5331ee8c18770c5f6b6d6427acd77956c402e0ebb81bf6e0868c773b7b0564336f24e4bc8d4c9e334abf4b978aa1f5f9f134ab04aca56c9cb83b6195456a2570ba8d676b09595ab91d52ac05336261d5b96ad368555d09d884a001d8b405df78e49f04fe77ed70690786d74df9d1e71c3000acb691f4b4542a0190c85696d2ba63dcab31c92387973aa50b2142df2c58b72cdb6648baa48e455a57e55b800cbf16cab48b6c382a0fddb452ff3b8e2a5d35a32b3d72732e847af299353fb35583d7e7062b6903395711fab9688aafddcd2f3fabc21cd7c6a4d98c76696ef763ea81f");
    BigInteger B("7748f535962cb140c2a77553d743dc3788abedbf814ba55f330f015237b18cbaaa741d8d85536325e175e6230a0e13655c8114706ce0c3d724f0e2f430f18359e4479a145a7286702a636d98f417fa5995e093c4fbfe8bc3f8415008a445d2d8b2dd651ac53c99719267ac7773b3eb21c046ea633177a67b3745ac772c6ed65931b12451ccdab30a5d62242138f2d01f73e76586569815b6f472d36286b0afe606b517a5cf1dddf8258b00b2a255d78298c2b32f56be1fc26c93340f6155a3243819f8db043dffee4cccc00a410470e5363c1b2ae8755f27e745e7bb38a1fb52e1");
    BigInteger C("85ee719c52f5a098c40bb33c7370bfbb018020cdd3704d8ffb9da90e7ed92b");
    ASSERT_EQ(A / B, C);
}

TEST(div, test3) {
    BigInteger A("d3a4330729b0c636f6adbe998c7703561ba2ccbf7c7554e1388efc37d5b8b97f321c84c2f70dd3c30ec75ae937bf757e4f5f03af6f98ea8fe82944fcc6ac14be7fdb42944eada47498793b707e02ac045cb54e7a112a710948cc5a20713f857cc47a46ebf9fbf4ea94bf801fa6fc10f04a8d712a18512e00ca01fbf66052e98ccc4a63a2a8e1d5cd8b31a95e1478f75cb38cc2b548c0f59eb34f9359b313a164f63d3dc14f080ad1dfd1bf96e8a487a98f2c7af9d48b7109654eff2381d4b3ecb927d29c41a27ddf601138c6fe931cc0c541354334f5a2d4da603a8c3e5bcd61ae24145b3aa2fd91e87e37b5dd4804a84aa1c961382aa39b67fa43047244ecdb");
    BigInteger B("1");
    BigInteger C("d3a4330729b0c636f6adbe998c7703561ba2ccbf7c7554e1388efc37d5b8b97f321c84c2f70dd3c30ec75ae937bf757e4f5f03af6f98ea8fe82944fcc6ac14be7fdb42944eada47498793b707e02ac045cb54e7a112a710948cc5a20713f857cc47a46ebf9fbf4ea94bf801fa6fc10f04a8d712a18512e00ca01fbf66052e98ccc4a63a2a8e1d5cd8b31a95e1478f75cb38cc2b548c0f59eb34f9359b313a164f63d3dc14f080ad1dfd1bf96e8a487a98f2c7af9d48b7109654eff2381d4b3ecb927d29c41a27ddf601138c6fe931cc0c541354334f5a2d4da603a8c3e5bcd61ae24145b3aa2fd91e87e37b5dd4804a84aa1c961382aa39b67fa43047244ecdb");
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
