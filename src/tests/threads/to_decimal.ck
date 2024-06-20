# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(to_decimal) begin
(to_decimal) Actual 0
(to_decimal) Actual 16384
(to_decimal) Actual 49152
(to_decimal) Actual -16384
(to_decimal) Actual -49152
(to_decimal) Actual 2147467264
(to_decimal) Actual -2147483648
(to_decimal) Actual -1
(to_decimal) Actual -1
(to_decimal) end
EOF
pass;
