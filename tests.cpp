#include "tests.h"

void InitializingFixture::SetUp() {
    actualHexNumber = GetParam();
    bigNumber.setHex(actualHexNumber);
}

void InvOperationFixture::SetUp() {
    bigNumber.setHex(GetParam());
}

void XorOperationFixture::SetUp() {
    std::tuple<std::string, std::string, std::string> operands = GetParam();
    firstBigNumber.setHex(get<0>(operands));
    secondBigNumber.setHex(get<1>(operands));
    expectedResult.setHex(get<2>(operands));
}

void OrOperationFixture::SetUp() {
    std::tuple<std::string, std::string, std::string> operands = GetParam();
    firstBigNumber.setHex(get<0>(operands));
    secondBigNumber.setHex(get<1>(operands));
    expectedResult.setHex(get<2>(operands));
}

void AndOperationFixture::SetUp() {
    std::tuple<std::string, std::string, std::string> operands = GetParam();
    firstBigNumber.setHex(get<0>(operands));
    secondBigNumber.setHex(get<1>(operands));
    expectedResult.setHex(get<2>(operands));
}

void ShiftROperationFixture::SetUp() {
    std::pair<std::string, std::string> operands = GetParam();
    bigNumber.setHex(operands.first);
    expectedResult = operands.second;
}

void ShiftLOperationFixture::SetUp() {
    std::pair<std::string, std::string> operands = GetParam();
    bigNumber.setHex(operands.first);
    expectedResult = operands.second;
}

void AddOperationFixture::SetUp() {
    std::tuple<std::string, std::string, std::string> operands = GetParam();
    firstBigNumber.setHex(get<0>(operands));
    secondBigNumber.setHex(get<1>(operands));
    expectedResult.setHex(get<2>(operands));
}

void SubOperationFixture::SetUp() {
    std::tuple<std::string, std::string, std::string> operands = GetParam();
    firstBigNumber.setHex(get<0>(operands));
    secondBigNumber.setHex(get<1>(operands));
    expectedResult.setHex(get<2>(operands));
}

void ModOperationFixture::SetUp() {
    std::tuple<std::string, std::string, std::string> operands = GetParam();
    bigNumber.setHex(get<0>(operands));
    divider.setHex(get<1>(operands));
    expectedResult.setHex(get<2>(operands));
}

TEST_P(InitializingFixture, Initializing) {
    EXPECT_EQ(bigNumber.getHex(), actualHexNumber);
}

TEST_P(InvOperationFixture, InvOperation) {
    bigInt doublyInvBigNumber = bigNumber;
    doublyInvBigNumber.INV();
    doublyInvBigNumber.INV();
    EXPECT_EQ(bigNumber, doublyInvBigNumber);
}

TEST_P(XorOperationFixture, XorOperation) {
    firstBigNumber.XOR(secondBigNumber);
    EXPECT_EQ(firstBigNumber.getHex(), expectedResult.getHex());
}

TEST_P(OrOperationFixture, OrOperation) {
    firstBigNumber.OR(secondBigNumber);
    EXPECT_EQ(firstBigNumber.getHex(), expectedResult.getHex());
}

TEST_P(AndOperationFixture, AndOperation) {
    firstBigNumber.AND(secondBigNumber);
    EXPECT_EQ(firstBigNumber.getHex(), expectedResult.getHex());
}

TEST_P(ShiftROperationFixture, ShiftROperation) {
    bigNumber.shiftR(3);
    EXPECT_EQ(bigNumber.getHex(), expectedResult);
}

TEST_P(ShiftLOperationFixture, ShiftLOperation) {
    bigNumber.shiftL(3);
    EXPECT_EQ(bigNumber.getHex(), expectedResult);
}

TEST_P(AddOperationFixture, AddOperation) {
    firstBigNumber.ADD(secondBigNumber);
    EXPECT_EQ(firstBigNumber.getHex(), expectedResult.getHex());
}

TEST(NotValidSubOperation, SubOperation) {
    bigInt firstBigNumber, secondBigNumber;
    firstBigNumber.setHex("22e962951cb6cd2ce279ab0e2095825c141d48ef3ca9dabf253e38760b57fe03");
    secondBigNumber.setHex(
            "33ced2c76b26cae94e162c4c0d2c0ff7c13094b0185a3c122e732d5ba77efebc"
            );
    EXPECT_THROW(firstBigNumber.SUB(secondBigNumber), std::invalid_argument);
}

TEST_P(SubOperationFixture, ValidSubOperation) {
    firstBigNumber.SUB(secondBigNumber);
    EXPECT_EQ(firstBigNumber.getHex(), expectedResult.getHex());
}

TEST_P(ModOperationFixture, ModOperation) {
    bigInt actualResult = bigNumber.MOD(divider);
    EXPECT_EQ(actualResult.getHex(), expectedResult.getHex());
}

INSTANTIATE_TEST_CASE_P(Initializing, InitializingFixture, testing::Values(
            "22e962951cb6cd2ce279ab0e2095825c141d48ef3ca9dabf253e38760b57fe03",
            "0",
            "10e570324e6ffdbc6b9c813dec968d9bad134bc0dbb061530934f4e59c2700b9",
            "97f92a75b3faf8939e8e98b96476fd22",
            "4a7f69b908e167eb0dc9af7bbaa5456039c38359e4de4f169ca10c44d0a416e2"
        ));

INSTANTIATE_TEST_CASE_P(InvOperation, InvOperationFixture, testing::Values(
            "22e962951cb6cd2ce279ab0e2095825c141d48ef3ca9dabf253e38760b57fe03",
            "0",
            "10e570324e6ffdbc6b9c813dec968d9bad134bc0dbb061530934f4e59c2700b9",
            "97f92a75b3faf8939e8e98b96476fd22",
            "4a7f69b908e167eb0dc9af7bbaa5456039c38359e4de4f169ca10c44d0a416e2"
));

INSTANTIATE_TEST_CASE_P(XorOperation, XorOperationFixture, testing::Values(
        std::make_tuple<std::string, std::string, std::string>(
                "51bf608414ad57",
                "403db8ad88a3",
                "51ff5d3cb925f4"
                ),
        std::make_tuple<std::string, std::string, std::string>(
                "51bf608414ad57",
                "403db8ad88a393",
                "1182d8299c0ec4"
                ),
        std::make_tuple<std::string, std::string, std::string>(
                "51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4",
                "403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c",
                "1182d8299c0ec40ca8bf3f49362e95e4ecedaf82bfd167988972412095b13db8"
        )
));

INSTANTIATE_TEST_CASE_P(OrOperation, OrOperationFixture, testing::Values(
        std::make_tuple<std::string, std::string, std::string>(
                "51bf608414ad57",
                "403db8ad88a3",
                "51ff7dbcbdadf7"
        ),
        std::make_tuple<std::string, std::string, std::string>(
                "51bf608414ad57",
                "403db8ad88a393",
                "51bff8ad9cafd7"
        ),
        std::make_tuple<std::string, std::string, std::string>(
                "51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4",
                "403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c",
                "51bff8ad9cafd72eabffbfc9befffffffcffbffaffdd779afdf3d7fdf7f73fbc"
        )
));

INSTANTIATE_TEST_CASE_P(AndOperation, AndOperationFixture, testing::Values(
        std::make_tuple<std::string, std::string, std::string>(
                "51bf608414ad57",
                "403db8ad88a3",
                "00002080048803"
        ),
        std::make_tuple<std::string, std::string, std::string>(
                "51bf608414ad57",
                "403db8ad88a393",
                "403d208400a113"
        ),
        std::make_tuple<std::string, std::string, std::string>(
                "51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4",
                "403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c",
                "403d208400a113220340808088d16a1b10121078400c1002748196dd62460204"
        )
));

INSTANTIATE_TEST_CASE_P(ShiftROperation, ShiftROperationFixture, testing::Values(
        std::make_pair<std::string, std::string>(
                "51bf608414ad57",
                "26fd009284bbe0"
        ),
        std::make_pair<std::string, std::string>(
                "51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4",
                "26fd009284bbe4c47836d9121ffe636b8ef75e0fe1bb405f883afebdd8e0c590"
        ),
        std::make_pair<std::string, std::string>(
                "403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c",
                "06a715b1157274416fc13035db3ddff71342af591a87a24eb772dabf6ed66281"
        )
));

INSTANTIATE_TEST_CASE_P(ShiftLOperation, ShiftLOperationFixture, testing::Values(
        std::make_pair<std::string, std::string>(
                "51bf608414ad57",
                "8a8d7304a02dea"
        ),
        std::make_pair<std::string, std::string>(
                "51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4",
                "8a8d7304a02dea313d1e857684cfbbd8d2aff593cb7ce214d32e8ebf673a3075"
        ),
        std::make_pair<std::string, std::string>(
                "403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c",
                "0289e54d644d9c1158d37c0c45fe47fff5c098e75682e9a09fed94beeb97b990"
        )
));

INSTANTIATE_TEST_CASE_P(AddOperation, AddOperationFixture, testing::Values(
        std::make_tuple<std::string, std::string, std::string>(
                "51bf608414ad57",
                "403db8ad88a3",
                "51ff9e3cc235fa"
        ),
        std::make_tuple<std::string, std::string, std::string>(
                "51bf608414ad57",
                "403db8ad88a393",
                "91fd19319d50ea"
        ),
        std::make_tuple<std::string, std::string, std::string>(
                "36f028580bb02cc8272a9a020f4200e346e276ae664e45ee80745574e2f5ab80",
                "70983d692f648185febe6d6fa607630ae68649f7e6fc45b94680096c06e4fadb",
                "a78865c13b14ae4e25e90771b54963ee2d68c0a64d4a8ba7c6f45ee0e9daa65b"
        )
));

INSTANTIATE_TEST_CASE_P(ValidSubOperation, SubOperationFixture, testing::Values(
        std::make_tuple<std::string, std::string, std::string>(
                "51bf608414ad57",
                "403db8ad88a3",
                "27f22cb6724b4"
        ),
        std::make_tuple<std::string, std::string, std::string>(
                "51bf608414ad57",
                "403db8ad88a393",
                "1181a7d68c09c4"
        ),
        std::make_tuple<std::string, std::string, std::string>(
                "33ced2c76b26cae94e162c4c0d2c0ff7c13094b0185a3c122e732d5ba77efebc",
                "22e962951cb6cd2ce279ab0e2095825c141d48ef3ca9dabf253e38760b57fe03",
                "10e570324e6ffdbc6b9c813dec968d9bad134bc0dbb061530934f4e59c2700b9"
        )
));

INSTANTIATE_TEST_CASE_P(ModOperation, ModOperationFixture, testing::Values(
        std::make_tuple<std::string, std::string, std::string>(
                "0",
                "3",
                "0"
        ),
        std::make_tuple<std::string, std::string, std::string>(
                "51bf608414ad57",
                "403db8ad88a393",
                "143ef29036631"
        ),
        std::make_tuple<std::string, std::string, std::string>(
                "33ced2c76b26cae94e162c4c0d2c0ff7c13094b0185a3c122e732d5ba77efebc",
                "10e570324e6ffdbc6b9c813dec968d9bad134bc0dbb061530934f4e59c2700b9",
                "22e962951cb6cd2ce279ab0e2095825c141d48ef3ca9dabf253e38760b57fe03"
        )
));