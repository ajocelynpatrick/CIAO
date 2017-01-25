// -*- C++ -*-
/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0.1
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
 *     http://www.dre.vanderbilt.edu/~schmidt/TAO.html
 **/
#ifndef CIAO_COMPONENT2_EXEC_0KVRT6_H_
#define CIAO_COMPONENT2_EXEC_0KVRT6_H_

#include /**/ "ace/pre.h"

#include "Component2EC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Component2_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_Threading_Component2_Impl
{

  /**
   * Provider Executor Implementation Class: prov_interface_2_exec_i
   */

  class prov_interface_2_exec_i
    : public virtual ::Threading::CCM_interface_2,
      public virtual ::CORBA::LocalObject
  {
  public:
    prov_interface_2_exec_i (
      ::Threading::CCM_Component2_Context_ptr ctx);
    virtual ~prov_interface_2_exec_i (void);

    /** @name Operations and attributes from Threading::interface_2 */
    //@{

    virtual
    void invoke_on_interface_2 (void);
    //@}

  private:
    ::Threading::CCM_Component2_Context_var ciao_context_;
  };

  /**
   * Component Executor Implementation Class: Component2_exec_i
   */

  class Component2_exec_i
    : public virtual Component2_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Component2_exec_i (void);
    virtual ~Component2_exec_i (void);

    /** @name Supported operations and attributes. */
    //@{

    //@}

    /** @name Component attributes and port operations. */
    //@{

    virtual ::Threading::CCM_interface_2_ptr
    get_prov_interface_2 (void);
    //@}

    /** @name Operations from Components::SessionComponent. */
    //@{
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    virtual void configuration_complete (void);
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    /** @name User defined public operations. */
    //@{

    //@}

  private:
    ::Threading::CCM_Component2_Context_var ciao_context_;

    /** @name Component attributes. */
    //@{
    ::Threading::CCM_interface_2_var ciao_prov_interface_2_;
    //@}

    /** @name User defined members. */
    //@{

    //@}

    /** @name User defined private operations. */
    //@{

    //@}
  };

  extern "C" COMPONENT2_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Threading_Component2_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */