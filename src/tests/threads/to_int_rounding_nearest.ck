# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(to_int_rounding_nearest) begin
(to_int_rounding_nearest) Actual 0
(to_int_rounding_nearest) Actual 1
(to_int_rounding_nearest) Actual 3
(to_int_rounding_nearest) Actual -1
(to_int_rounding_nearest) Actual -3
(to_int_rounding_nearest) Actual 131071
(to_int_rounding_nearest) Actual -131071
(to_int_rounding_nearest) end
EOF
pass;
