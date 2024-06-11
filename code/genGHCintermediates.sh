#!/usr/bin/env sh

# the GHC intermediates I talked about in the presentation which helped me for
# prep

stack ghc -- double.hs \
            -ddump-to-file \
            -ddump-file-prefix="dump" \
            -ddump-simpl \
            -ddump-inlinings \
            -ddump-stg-from-core \
            -ddump-stg-final \
            -ddump-cmm-verbose \
            -ddump-asm-native
