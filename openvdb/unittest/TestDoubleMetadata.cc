///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2012-2014 DreamWorks Animation LLC
//
// All rights reserved. This software is distributed under the
// Mozilla Public License 2.0 ( http://www.mozilla.org/MPL/2.0/ )
//
// Redistributions of source code must retain the above copyright
// and license notice and the following restrictions and disclaimer.
//
// *     Neither the name of DreamWorks Animation nor the names of
// its contributors may be used to endorse or promote products derived
// from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// IN NO EVENT SHALL THE COPYRIGHT HOLDERS' AND CONTRIBUTORS' AGGREGATE
// LIABILITY FOR ALL CLAIMS REGARDLESS OF THEIR BASIS EXCEED US$250.00.
//
///////////////////////////////////////////////////////////////////////////

#include <cppunit/extensions/HelperMacros.h>
#include <openvdb/Exceptions.h>
#include <openvdb/Metadata.h>

class TestDoubleMetadata : public CppUnit::TestCase
{
public:
    CPPUNIT_TEST_SUITE(TestDoubleMetadata);
    CPPUNIT_TEST(test);
    CPPUNIT_TEST_SUITE_END();

    void test();
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestDoubleMetadata);

void
TestDoubleMetadata::test()
{
    using namespace openvdb;

    Metadata::Ptr m(new DoubleMetadata(1.23));
    Metadata::Ptr m2 = m->copy();

    CPPUNIT_ASSERT(dynamic_cast<DoubleMetadata*>(m.get()) != 0);
    CPPUNIT_ASSERT(dynamic_cast<DoubleMetadata*>(m2.get()) != 0);

    CPPUNIT_ASSERT(m->typeName().compare("double") == 0);
    CPPUNIT_ASSERT(m2->typeName().compare("double") == 0);

    DoubleMetadata *s = dynamic_cast<DoubleMetadata*>(m.get());
    //CPPUNIT_ASSERT(s->value() == 1.23);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1.23,s->value(),0);
    s->value() = 4.56;
    //CPPUNIT_ASSERT(s->value() == 4.56);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(4.56,s->value(),0);

    m2->copy(*s);

    s = dynamic_cast<DoubleMetadata*>(m2.get());
    //CPPUNIT_ASSERT(s->value() == 4.56);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(4.56,s->value(),0);
}

// Copyright (c) 2012-2014 DreamWorks Animation LLC
// All rights reserved. This software is distributed under the
// Mozilla Public License 2.0 ( http://www.mozilla.org/MPL/2.0/ )
