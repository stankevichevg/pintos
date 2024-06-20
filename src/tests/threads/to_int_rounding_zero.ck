# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(to_int_rounding_zero) begin
(to_int_rounding_zero) Actual 0
(to_int_rounding_zero) Actual 1
(to_int_rounding_zero) Actual 3
(to_int_rounding_zero) Actual -1
(to_int_rounding_zero) Actual -3
(to_int_rounding_zero) Actual 131071
(to_int_rounding_zero) Actual -131072
(to_int_rounding_zero) end
EOF
pass;
