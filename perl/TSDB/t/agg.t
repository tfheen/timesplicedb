

use Test::More tests => 40;
BEGIN { use_ok('TSDB') };

use strict;

unlink("aggtest.ngrd");

my $ct = 1258091219;
my $it = $ct;
my $tsdb = TSDB->new('aggtest.ngrd',
    clobber     => 1,
    resolution  => 60,
    columns     => 'test',
    create_time => $ct);

foreach(1..9) {
  $tsdb->insert('test' => $_, $it);
  $it += 60;
}


is($tsdb->rows, 9);

my $range = $tsdb->timespan($ct, $it - 60);

isa_ok($range, "TSDB::Range");
is($range->rows, 9);

for(1..9) {
  my $cell = $range->cell($_-1, 'test');

  is_deeply($cell, {
		     stddev => 0,
		     min    => $_,
		     value  => $_,
		     max    => $_,
		     avg    => $_,
		     row    => $_-1,
		     time   => 0,
		     rows_averaged => 0,
		    }, "row, this is not aggregated");
}


my $agg = $range->aggregate(120);

isa_ok($range, "TSDB::Range");
is($agg->rows, 5);

{
  my $cell = $agg->cell(0, 'test');
  is($cell->{stddev}, 0.5, "stddev");
  is($cell->{min}, 1, "lowest we have seen");
  is($cell->{max}, 2, "highest we have seen");
  is($cell->{avg}, 1.5 , "between 1 and 2");
  is($cell->{rows_averaged}, 2, "this bucket should have two entries!");
}

{
  my $cell = $agg->cell(1, 0);
  is($cell->{stddev}, 0.5, "stddev");
  is($cell->{min}, 3, "lowest we have seen");
  is($cell->{max}, 4, "highest we have seen");
  is($cell->{avg}, 3.5 , "between 3 and 4");
  is($cell->{rows_averaged}, 2, "this bucket should have two entries!");
}

{
  my $cell = $agg->cell(2, 'test');
  is($cell->{stddev}, 0.5, "stddev");
  is($cell->{min}, 5, "lowest we have seen");
  is($cell->{max}, 6, "highest we have seen");
  is($cell->{avg}, 5.5 , "between 5 and 6");
  is($cell->{rows_averaged}, 2, "this bucket should have two entries!");
}

{
  my $cell = $agg->cell(3, 0);
  is($cell->{stddev}, 0.5, "stddev");
  is($cell->{min}, 7, "lowest we have seen");
  is($cell->{max}, 8, "highest we have seen");
  is($cell->{avg}, 7.5 , "between 7 and 8");
  is($cell->{rows_averaged}, 2, "this bucket should have two entries!");
}

{
  my $cell = $agg->cell(4, 'test');
  is($cell->{stddev}, 0, "no stddev");
  is($cell->{min}, 9, "lowest we have seen");
  is($cell->{max}, 9, "highest we have seen");
  is($cell->{avg}, 9 , "only one in this bucket 9");
  is($cell->{rows_averaged}, 1, "this bucket should have two entries!");
}


