// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.2
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/
#ifndef CIAO__________TUTORIAL_CODE_GENERATEDEXEC_HELLO_RECEIVER_COMP_EXEC_IHOFDC_H_
#define CIAO__________TUTORIAL_CODE_GENERATEDEXEC_HELLO_RECEIVER_COMP_EXEC_IHOFDC_H_

#include /**/ "ace/pre.h"

#include "Hello_Receiver_compEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"

namespace CIAO_Hello_Receiver_comp_Impl
{

  //============================================================
  // Provider Executor Implementation Class: do_my_foo_exec_i
  //============================================================

  class  do_my_foo_exec_i
    : public virtual ::Hello::CCM_MyFoo_obj,
      public virtual ::CORBA::LocalObject
  {
  public:
    do_my_foo_exec_i (
      ::Hello::CCM_Receiver_comp_Context_ptr ctx);
    virtual ~do_my_foo_exec_i (void);

    // Operations and attributes from ::Hello::MyFoo_obj

    virtual
    ::CORBA::Long foo (const char * in_str,
    ::CORBA::String_out answer);

    virtual
    void hello (::CORBA::Long_out answer);

    virtual ::CORBA::Short rw_attrib (void);

    virtual void rw_attrib (::CORBA::Short rw_attrib);

    virtual ::CORBA::Short ro_attrib (void);

  private:
    ::Hello::CCM_Receiver_comp_Context_var ciao_context_;
  };

  //============================================================
  // Component Executor Implementation Class: Receiver_comp_exec_i
  //============================================================

  class  Receiver_comp_exec_i
    : public virtual Receiver_comp_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Receiver_comp_exec_i (void);
    virtual ~Receiver_comp_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::Hello::CCM_MyFoo_obj_ptr
    get_do_my_foo (void);//@}

    //@{
    /** Operations from Components::SessionComponent. */

    virtual void set_session_context (::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    //@{
    /** User defined operations */

    //@}

  private:
    ::Hello::CCM_Receiver_comp_Context_var ciao_context_;
    ::Hello::CCM_MyFoo_obj_var ciao_do_my_foo_;
  };

  extern "C"  ::Components::EnterpriseComponent_ptr
  create_Hello_Receiver_comp_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
