#ifndef RIGTFORM_H
#define RIGTFORM_H

#include <iostream>
#include <cassert>

#include "matrix4.h"
#include "quat.h"

class RigTForm {
  Cvec3 t_; // translation component
  Quat r_;  // rotation component represented as a quaternion

public:
  RigTForm() : t_(0) {
    assert(norm2(Quat(1,0,0,0) - r_) < CS175_EPS2);
  }

  RigTForm(const Cvec3& t, const Quat& r) {
    t_ = t;
    r_ = r;
  }

  explicit RigTForm(const Cvec3& t) {
    RigTForm(t, r_); // TODO 
  }

  explicit RigTForm(const Quat& r) {
    RigTForm(t_, r); // TODO 
  }

  Cvec3 getTranslation() const {
    return t_;
  }

  Quat getRotation() const {
    return r_;
  }

  RigTForm& setTranslation(const Cvec3& t) {
    t_ = t;
    return *this;
  }

  RigTForm& setRotation(const Quat& r) {
    r_ = r;
    return *this;
  }

  Cvec4 operator * (const Cvec4& a) const {
    if (a[3] == 0) {
      return r_ * a;
    }
    return r_ * a + Cvec4(t_, 0);
  }

  RigTForm operator * (const RigTForm& a) const {
    Cvec3 foo = Cvec3(Cvec4(t_, 0) + r_ * Cvec4(a.t_, 0));
    Quat bar = r_ * a.r_;
    return RigTForm(foo, bar);
  }
};

inline RigTForm inv(const RigTForm& tform) {
  // TODO
}

inline RigTForm transFact(const RigTForm& tform) {
  return RigTForm(tform.getTranslation());
}

inline RigTForm linFact(const RigTForm& tform) {
  return RigTForm(tform.getRotation());
}

inline Matrix4 rigTFormToMatrix(const RigTForm& tform) {
  // TODO
  // return m;
  return NULL;
}

#endif