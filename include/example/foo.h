#pragma once
#include <string>

// A "forward declaration" to a function defined elsewhere.


namespace example
{
	void func();

	class Foo
	{
	private:
		std::string name;
		unsigned int age;
	public:
		Foo(std::string n, unsigned a);
		Foo();
		~Foo();

		// Called when the user does this:
		// some_foo + i, and that it returns a Foo object
		Foo operator+(int i);


		void some_method();

		friend void func();
		friend class AnotherClass;		// This class is defined
										// elsewhere and in all methods,attributes,
										// etc. IT has access to private things
										// declared here.
		
		// This one is "weird" in that we're making the function here in the
		// class, but it's considered to be OUTSIDE the class for access rules
		// BUT we're making it a friend.  Weird also in that it's put in the
		// GLOBAL NAMESPACE
		friend void weird_func(Foo& a_foo)
		{
			a_foo.age += 2;
		}


		friend Foo operator+(int i, Foo& right_foo)
		{
			return right_foo + i;
		}
	};


	// Make a FUNCTION to do "reverse add"
	//Foo operator+(int i, Foo right_foo);
}