/* gen164/5/ed_scalarmult_base.c
**
*/
#include "all.h"
#include <urcrypt.h>

/* functions
*/
  static u3_atom
  _cqee_scalarmult_base(u3_atom a)
  {
    c3_w met_w = u3r_met(3, a);

    if ( met_w > 32 ) {
      return u3_none;
    }
    else {
      c3_y a_y[32], out_y[32];

      memset(a_y, 0, 32);
      u3r_bytes(0, met_w, a_y, a);

      urcrypt_ed_scalarmult_base(a_y, out_y);
      return u3i_bytes(32, out_y);
    }
  }

  u3_noun
  u3wee_scalarmult_base(u3_noun cor)
  {
    u3_noun a = u3r_at(u3x_sam, cor);

    if ( (u3_none == a) || (c3n == u3ud(a)) ) {
      return u3m_bail(c3__exit);
    }
    else {
      return _cqee_scalarmult_base(a);
    }
  }
