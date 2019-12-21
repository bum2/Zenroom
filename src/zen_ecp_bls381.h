// Zenroom ECP module
//
// (c) Copyright 2017-2020 Dyne.org foundation
// designed, written and maintained by Denis Roio <jaromil@dyne.org>
//
// This program is free software: you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// version 3 as published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this program.  If not, see
// <http://www.gnu.org/licenses/>.

// All static and generated code because runtime pointers won't work
// in ECP where we also need to change BIG types according to
// curve. So we are not using a factory like in ECDH here.

#ifndef __ZEN_ECP_BLS381_H__

#include <ecp_BLS381.h>
#include <ecp2_BLS381.h>
#include <ecdh_BLS381.h>
#include <pair_BLS381.h>

#define BIGSIZE 384
#include <zen_big_types.h>
#include <zen_ecp.h>

#define CURVE_A CURVE_A_BLS381
#define CURVE_B Curve_B_BLS381
#define CURVE_B_I CURVE_B_I_BLS381
#define CURVE_Gx CURVE_Gx_BLS381
#define CURVE_Gy CURVE_Gy_BLS381
#define CURVE_Order CURVE_Order_BLS381
#define CURVE_Cofactor CURVE_Cof_BLS381
#define CURVE_G2xa CURVE_Pxa_BLS381
#define CURVE_G2xb CURVE_Pxb_BLS381
#define CURVE_G2ya CURVE_Pya_BLS381
#define CURVE_G2yb CURVE_Pyb_BLS381

#define ECP_copy(d,s) ECP_BLS381_copy(d,s)
#define ECP_set(d,x,y) ECP_BLS381_set(d, x, y)
#define ECP_setx(d,x,n) ECP_BLS381_setx(d, x, n)
#define ECP_affine(d) ECP_BLS381_affine(d)
#define ECP_inf(d) ECP_BLS381_inf(d)
#define ECP_isinf(d) ECP_BLS381_isinf(d)
#define ECP_unity(d) ECP_BLS381_isunity(d)
#define ECP_parity(d) ECP_BLS381_parity(d)
#define ECP_add(d,s) ECP_BLS381_add(d,s)
#define ECP_sub(d,s) ECP_BLS381_sub(d,s)
#define ECP_neg(d) ECP_BLS381_neg(d)
#define ECP_dbl(d) ECP_BLS381_dbl(d)
#define ECP_mul(d,b) ECP_BLS381_mul(d,b)
#define ECP_equals(l,r) ECP_BLS381_equals(l,r)
#define ECP_fromOctet(d,o) ECP_BLS381_fromOctet(d, o)
#define ECP_toOctet(o,d,b) ECP_BLS381_toOctet(o,d,b)
#define ECP_generator(e) ECP_BLS381_generator(e)
#define ECP_mapit(q,w) ECP_BLS381_mapit(q,w)
#define ECP_validate(o) ECP_BLS381_PUBLIC_KEY_VALIDATE(o)

#define FP2 FP2_BLS381
#define FP2_from_BIGs(x,a,b) FP2_BLS381_from_BIGs(x,a,b)

#define ECP2_copy(d,s) ECP2_BLS381_copy(d,s)
#define ECP2_set(d,x,y) ECP2_BLS381_set(d, x, y)
#define ECP2_setx(d,x) ECP2_BLS381_setx(d, x)
#define ECP2_affine(d) ECP2_BLS381_affine(d)
#define ECP2_inf(d) ECP2_BLS381_inf(d)
#define ECP2_isinf(d) ECP2_BLS381_isinf(d)
#define ECP2_add(d,s) ECP2_BLS381_add(d,s)
#define ECP2_sub(d,s) ECP2_BLS381_sub(d,s)
#define ECP2_neg(d) ECP2_BLS381_neg(d)
#define ECP2_dbl(d) ECP2_BLS381_dbl(d)
#define ECP2_mul(d,b) ECP2_BLS381_mul(d,b)
#define ECP2_equals(l,r) ECP2_BLS381_equals(l,r)
#define ECP2_fromOctet(d,o) ECP2_BLS381_fromOctet(d, o)
#define ECP2_toOctet(o,d) ECP2_BLS381_toOctet(o,d)
#define ECP2_generator(e) ECP2_BLS381_generator(e)
#define ECP2_mapit(q,w) ECP2_BLS381_mapit(q,w)

#define PAIR_ate(r,p,q) PAIR_BLS381_ate(r,p,q)
#define PAIR_fexp(x) PAIR_BLS381_fexp(x)
#define PAIR_G2mul(p,b)	PAIR_BLS381_G2mul(p,b)
#define PAIR_G1mul(p,b) PAIR_BLS381_G1mul(p,b)

#endif