#ifndef CMPLETEST_HPP_
#define CMPLETEST_HPP_

#include <cppunit/extensions/HelperMacros.h>

class CmpleTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(CmpleTest);

#if defined(MIPP_BW)
	CPPUNIT_TEST(test_reg_cmple_int8);
	CPPUNIT_TEST(test_Reg_cmple_int8);

	CPPUNIT_TEST(test_reg_cmple_int16);
	CPPUNIT_TEST(test_Reg_cmple_int16);
#endif

#if !defined(MIPP_AVX) || (defined(MIPP_AVX) && MIPP_INSTR_VERSION >= 2)
	CPPUNIT_TEST(test_reg_cmple_int32);
	CPPUNIT_TEST(test_Reg_cmple_int32);
#endif

	CPPUNIT_TEST(test_reg_cmple_float);
	CPPUNIT_TEST(test_Reg_cmple_float);

#if defined(MIPP_64BIT)
#if !defined(MIPP_AVX) || (defined(MIPP_AVX) && MIPP_INSTR_VERSION >= 2)
#if !defined(MIPP_SSE)
	CPPUNIT_TEST(test_reg_cmple_int64);
	CPPUNIT_TEST(test_Reg_cmple_int64);
#endif
#endif

	CPPUNIT_TEST(test_reg_cmple_double);
	CPPUNIT_TEST(test_Reg_cmple_double);
#endif

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	template <typename T>
	void test_reg_cmple();
	void test_reg_cmple_int8();
	void test_reg_cmple_int16();
	void test_reg_cmple_int32();
	void test_reg_cmple_int64();
	void test_reg_cmple_float();
	void test_reg_cmple_double();

	template <typename T>
	void test_Reg_cmple();
	void test_Reg_cmple_int8();
	void test_Reg_cmple_int16();
	void test_Reg_cmple_int32();
	void test_Reg_cmple_int64();
	void test_Reg_cmple_float();
	void test_Reg_cmple_double();
};

#endif  // CMPLETEST_HPP_