/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    varout.h
//
// = DESCRIPTION
//     Templates for _var and _out types
//
// = AUTHOR
//
//   Aniruddha Gokhale
// ============================================================================

#if !defined (TAO_VAROUT_H)
#define TAO_VAROUT_H

class CORBA_Object;

template <class T>
class TAO_Object_Field_T : public TAO_Object_Field
{
  // = TITLE
  //   Parametric class to implement structure fields corresponding to
  //   object references.
  //
  // = DESCRIPTION
  //   When an object reference appears in a structure the marshaling
  //   and demarhsaling of the structure gets complicated:
  //   the interpreter can only marshal CORBA_Object_ptr when it
  //   dermarshal it creates on of those objects.
  //   The downcasting to the right type must be executed by classes
  //   with compile-time knowledge of the object type.
  //   The solution addopted in TAO is to create a special manager
  //   class for that field, 
public:
  TAO_Object_Field_T (void);
  // default constructor

  TAO_Object_Field_T (T* object);
  // constructor from a T*, assumes ownership of <object> i.e. it
  // *will* release it.

  TAO_Object_Field_T (const TAO_Object_Field_T<T> &);
  // copy constructor

  virtual ~TAO_Object_Field_T (void);
  // destructor

  TAO_Object_Field_T<T> &operator= (T* object);
  // Assignment from a T*, it assumes ownership of <object>.

  TAO_Object_Field_T<T> &operator= (const TAO_Object_Field_T<T> &);
  // Assignment operator, in duplicates the underlying objects.

  T* operator-> (void) const;
  // smart pointer (const)

  operator T* const &() const;
  // cast operator

  operator T* &();
  // cast operator

  // = operations for parameter passing modes

  T* in (void) const;
  // for in type parameter

  T* &inout (void);
  // for inout type parameter

  T* &out (void);
  // for out parameter

  T* _retn (void);
  // for return type

  T* ptr (void) const;
  // TAO extension for access to the underlying pointer.

  virtual void _downcast (CORBA_Object* base_ptr,
			  CORBA_Environment& env);
  virtual CORBA_Object* _upcast (void);
  virtual void _release (void);
  // Implement the TAO_Object_Field methods.

private:
  T* ptr_;
};

// ****************************************************************
// The following classes are experimental, some of them do *not*
// compile and produce errors in compilers that check templates before
// instantiation time. In the future we may use them to implement
// several classes generated by IDL compiler, possibly reducing the
// complexity of the compiler.
// ****************************************************************
#if 0
template <class T>
class TAO_Fixed_var
  // = TITLE
  //    template<class T> TAO_Fixed_var
  //
  // = DESCRIPTION
  //    Provides a parametrized version of the _var class for fixed
  //    length data structs and unions.
{
public:
  // = Operations

  TAO_Fixed_var (void);
  // default constructor

  TAO_Fixed_var (T *);
  // constructor from a pointer to T

  TAO_Fixed_var (const TAO_Fixed_var<T> &);
  // copy constructor

  ~TAO_Fixed_var (void);
  // destructor

  TAO_Fixed_var<T> &operator= (T *);
  // assignment from a pointer to T

  TAO_Fixed_var<T> &operator= (const TAO_Fixed_var<T> &);
  // assignment from a TAO_Fixed_var

  T *operator-> (void);
  // smart pointer

  const T *operator-> (void) const;
  // smart pointer (const)

  operator const T *&() const;
  // cast operator

  operator T *&();
  // cast operator

  // = Operations for parameter passing modes.

  const T &in (void);
  // for in type parameter

  T &inout (void);
  // for inout type parameter

  T &out (void);
  // for out parameter

  T _retn (void);
  // for return type

private:
  T *ptr_;
  // instance
};

template <class T>
class TAO_Variable_var
  // = TITLE
  //   template<class T> TAO_Variable_var
  //
  // = DESCRIPTION
  //   Provides a parametrized version of the _var class for Variable
  //   length data structs and unions.
{
public:
  // = Operations

  TAO_Variable_var (void);
  // default constructor

  TAO_Variable_var (T *);
  // constructor from a pointer to T

  TAO_Variable_var (const TAO_Variable_var<T> &);
  // copy constructor

  ~TAO_Variable_var (void);
  // destructor

  TAO_Variable_var<T> &operator= (T *);
  // assignment from a pointer to T

  TAO_Variable_var<T> &operator= (const TAO_Variable_var<T> &);
  // assignment from a TAO_Variable_var

  T *operator-> (void);
  // smart pointer

  const T *operator-> (void) const;
  // smart pointer (const)

  operator const T *&() const;
  // cast operator

  operator T *&();
  // cast operator

  // = operations for parameter passing modes

  const T &in (void);
  // for in type parameter

  T &inout (void);
  // for inout type parameter

  T *&out (void);
  // for out parameter

  T *_retn (void);
  // for return type

private:
  T *ptr_;
};

template <class T>
class TAO_Sequence_var
  // = TITLE
  //   template<class T> TAO_Sequence_var
  //
  // = DESCRIPTION
  //   Provides a parametrized version of the _var class for Sequence
  //   data type.  CORBA sequences are considered to always be
  //   variable length.
{
public:
  // = Operations

  TAO_Sequence_var (void);
  // default constructor

  TAO_Sequence_var (T *);
  // constructor from a pointer to T

  TAO_Sequence_var (const TAO_Sequence_var &);
  // copy constructor

  ~TAO_Sequence_var (void);
  // destructor

  TAO_Sequence_var<T> &operator= (T *);
  // assignment from a pointer to T

  TAO_Sequence_var<T> &operator= (const TAO_Sequence_var &);
  // assignment from a TAO_Sequence_var

  T *operator-> (void);
  // smart pointer

  const T *operator-> (void) const;
  // smart pointer (const)

  operator const T *&() const;
  // cast operator

  operator T *&();
  // cast operator

  // = additional operators for sequence

  T::ElemType &operator[] (CORBA::ULong);
  // operator [] that passes the argument to the [] operator of T

  // = operations for parameter passing modes

  const T &in (void);
  // for in type parameter

  T &inout (void);
  // for inout type parameter

  T *&out (void);
  // for out parameter

  T *_retn (void);
  // for return type

private:
  T *ptr_;
  // seq instance
};

template <class T, class T_ptr>
class TAO_Object_var
  // = TITLE
  //   template<class T, class T_ptr> TAO_Object_var
  //
  // = DESCRIPTION
  //   Provides a parametrized version of the _var class for obj
  //   references.
{
public:
  // =Operations

  TAO_Object_var (void);
  // default constructor

  TAO_Object_var (T_ptr);
  // constructor from a pointer to T

  TAO_Object_var (const TAO_Object_var<T,T_ptr> &);
  // copy constructor

  ~TAO_Object_var (void);
  // destructor

  TAO_Object_var<T_ptr> &operator= (T_ptr);
  // assignment from a pointer to T

  TAO_Object_var<T_ptr> &operator= (const TAO_Object_var<T,T_ptr> &);
  // assignment from a TAO_Object_var

  T_ptr operator-> (void) const;
  // smart pointer (const)

  operator const T_ptr &() const;
  // cast operator

  operator T_ptr &();
  // cast operator

  // = operations for parameter passing modes

  const T_ptr &in (void);
  // for in type parameter

  T_ptr &inout (void);
  // for inout type parameter

  T_ptr &out (void);
  // for out parameter

  T_ptr _retn (void);
  // for return type

private:
  T_ptr ptr_;
};

template <class T, class T_slice>
class TAO_FixedArray_var
  // = TITLE
  //   template<class T, class T_slice> TAO_FixedArray_var
  //
  // = DESCRIPTION
  //   Provides a parametrized version of the _var class for obj
  //   references.
{
public:
  // = Operations

  TAO_FixedArray_var (void);
  // default constructor

  TAO_FixedArray_var (T_slice *);
  // constructor from a pointer to T

  TAO_FixedArray_var (const TAO_FixedArray_var<T, T_slice> &);
  // copy constructor

  ~TAO_FixedArray_var (void);
  // destructor

  TAO_FixedArray_var<T, T_slice> &operator= (T_slice *);
  // assignment from a pointer to T

  TAO_FixedArray_var<T, T_slice> &operator= (const TAO_FixedArray_var<T, T_slice> &);
  // assignment from a TAO_FixedArray_var

  T_slice &operator[] (CORBA::ULong);
  // index

  const T_slice &operator[] (CORBA::ULong) const;
  // index

  operator const T_slice &() const;
  // cast operator

  operator T_slice &();
  // cast operator

  // = operations for parameter passing modes

  const T &in (void);
  // for in type parameter

  T &inout (void);
  // for inout type parameter

  T &out (void);
  // for out parameter

  T_slice *_retn (void);
  // for return type

private:
  T_slice *ptr_;
};

template <class T, class T_slice>
class TAO_VariableArray_var
  // = TITLE
  //   template<class T, class T_slice> TAO_VariableArray_var
  //
  // = DESCRIPTION
  //   Provides a parametrized version of the _var class for obj
  //   references.
{
public:
  // = Operations

  TAO_VariableArray_var (void);
  // default constructor

  TAO_VariableArray_var (T_slice *);
  // constructor from a pointer to T

  TAO_VariableArray_var (const TAO_VariableArray_var<T, T_slice> &);
  // copy constructor

  ~TAO_VariableArray_var (void);
  // destructor

  TAO_VariableArray_var<T, T_slice> &operator= (T_slice *);
  // assignment from a pointer to T

  TAO_VariableArray_var<T, T_slice> &operator= (const TAO_VariableArray_var<T, T_slice> &);
  // assignment from a TAO_VariableArray_var

  T_slice &operator[] (CORBA::ULong);
  // index

  const T_slice &operator[] (CORBA::ULong) const;
  // index

  operator const T_slice &() const;
  // cast operator

  operator T_slice &();
  // cast operator

  // = operations for parameter passing modes

  const T &in (void);
  // for in type parameter

  T &inout (void);
  // for inout type parameter

  T_slice *&out (void);
  // for out parameter

  T_slice *_retn (void);
  // for return type

private:
  T_slice *ptr_;
};

template <class T, class T_slice>
class TAO_FixedArray_forany
  // = TITLE
  //   template<class T, class T_slice> TAO_FixedArray_forany
  //
  // = DESCRIPTION
  //   Provides a parametrized version of the _var class for obj
  //   references.
{
public:
  // =Operations

  TAO_FixedArray_forany (void);
  // default constructor

  TAO_FixedArray_forany (T_slice *, CORBA::Boolean nocopy=0);
  // constructor from a pointer to T slice

  TAO_FixedArray_forany (const TAO_FixedArray_forany<T, T_slice> &);
  // copy constructor

  ~TAO_FixedArray_forany (void);
  // destructor

  TAO_FixedArray_forany<T, T_slice> &operator= (T_slice *);
  // assignment from a pointer to T

  TAO_FixedArray_forany<T, T_slice> &operator= (const TAO_FixedArray_forany<T, T_slice> &);
  // assignment from a TAO_FixedArray_forany

  T_slice &operator[] (CORBA::ULong);
  // index

  const T_slice &operator[] (CORBA::ULong) const;
  // index

  operator const T_slice &() const;
  // cast operator

  operator T_slice &();
  // cast operator

  // =operations for parameter passing modes

  const T &in (void);
  // for in type parameter

  T &inout (void);
  // for inout type parameter

  T &out (void);
  // for out parameter

  T_slice *_retn (void);
  // for return type

private:
  T_slice *ptr_;
};

template <class T, class T_slice>
class TAO_VariableArray_forany
  // = TITLE
  //   template<class T, class T_slice> TAO_VariableArray_forany
  //
  // = DESCRIPTION
  //   Provides a parametrized version of the _var class for obj
  //   references.
{
public:
  // =Operations

  TAO_VariableArray_forany (void);
  // default constructor

  TAO_VariableArray_forany (T_slice *, CORBA::Boolean nocopy=0);
  // constructor from a pointer to T slice

  TAO_VariableArray_forany (const TAO_VariableArray_forany<T, T_slice> &);
  // copy constructor

  ~TAO_VariableArray_forany (void);
  // destructor

  TAO_VariableArray_forany<T, T_slice> &operator= (T_slice *);
  // assignment from a pointer to T

  TAO_VariableArray_forany<T, T_slice> &operator= (const TAO_VariableArray_forany<T, T_slice> &);
  // assignment from a TAO_VariableArray_forany

  T_slice &operator[] (CORBA::ULong);
  // index

  const T_slice &operator[] (CORBA::ULong) const;
  // index

  operator const T_slice &() const;
  // cast operator

  operator T_slice &();
  // cast operator

  // =operations for parameter passing modes

  const T &in (void);
  // for in type parameter

  T &inout (void);
  // for inout type parameter

  T_slice *&out (void);
  // for out parameter

  T_slice *_retn (void);
  // for return type

private:
  T_slice *ptr_;
};

template <class T, class T_var>
class TAO_Variable_out
  // = TITLE
  //   TAO_Variable_out
  //
  // = Description
  //  _out class definition for variable size struct/union.
{
public:
  TAO_Variable_out (T *&);
  // constructor

  TAO_Variable_out (T_var &);
  // constructor

  TAO_Variable_out (TAO_Variable_out <T,T_var> &);
  // copy constructor

  TAO_Variable_out<T,T_var> &operator= (TAO_Variable_out<T,T_var> &);
  // assignment operator

  TAO_Variable_out<T,T_var> &operator= (T *);
  // assignment

  operator T *&();
  // cast

  T *&ptr (void);
  // ptr method, returns a pointer to class T

  T *operator-> (void);
  // arrow operator (smart pointer)

private:
  T *&ptr_;
};

template <class T, class T_var>
class TAO_Sequence_out
  // = TITLE
  //   TAO_Sequence_out
  //
  // = Description
  //   _out class definition for Sequence
{
public:
  TAO_Sequence_out (T *&);
  // constructor

  TAO_Sequence_out (T_var &);
  // constructor

  TAO_Sequence_out (TAO_Sequence_out <T,T_var> &);
  // copy constructor

  TAO_Sequence_out<T,T_var> &operator= (TAO_Sequence_out<T,T_var> &);
  // assignment operator

  TAO_Sequence_out<T,T_var> &operator= (T *);
  // assignment

  operator T *&();
  // cast

  T *&ptr (void);
  // ptr method, returns a pointer to class T

  T *operator-> (void);
  // arrow operator (smart pointer)

  T::ElemType operator[] (CORBA::ULong);
  // return the element at index i

private:
  T *&ptr_;
};

template <class T_ptr, class T_var>
class TAO_Object_out
{
  // = TITLE
  //   TAO_Object_out
  //
  // = Description
  //   _out class definition for Object
public:
  TAO_Object_out (T_ptr &);
  // constructor

  TAO_Object_out (T_var &);
  // constructor

  TAO_Object_out (TAO_Object_out <T_ptr,T_var> &);
  // copy constructor

  TAO_Object_out<T_ptr,T_var> &operator= (TAO_Object_out<T_ptr,T_var> &);
  // assignment operator

  TAO_Object_out<T_ptr,T_var> &operator= (const T_var &);
  // assignment operator

  TAO_Object_out<T_ptr,T_var> &operator= (T_ptr);
  // assignment

  operator T_ptr &();
  // cast

  T_ptr &ptr (void);
  // ptr method, returns a pointer to class T

  T_ptr operator-> (void);
  // arrow operator (smart pointer)

private:
  T_ptr &ptr_;
};
#endif /* 0 */ 

#if defined (__ACE_INLINE__)
#include "tao/varout.i"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "tao/varout.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("varout.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* TAO_VAROUT_H */
