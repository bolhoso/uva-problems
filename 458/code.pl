#!/usr/bin/perl

my $dic = {};

my $codes = [q(1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5),
q(1PIT'pz'h'{yhklthyr'vm'{ol'Pu{lyuh{pvuhs'I|zpulzz'Thjopul'Jvywvyh{pvu5),
q(1KLJ'pz'{ol'{yhklthyr'vm'{ol'Kpnp{hs'Lx|pwtlu{'Jvywvyh{pvu5)
];

my $f1 = [q(*CDC is the trademark of the Control Data Corporation.),
q(*IBM is a trademark of the International Business Machine Corporation.),
q(*DEC is the trademark of the Digital Equipment Corporation.)];

foreach my $curr_code (@$codes) {
  my $curr_plain = shift (@$f1);
  while (my $char = chop ($curr_code)) {
    $dic->{$char} = chop ($curr_plain);
  }
}

print $_ . " (" . ord($_) . "): " .  $dic->{$_} . "(" . ord ($dic->{$_}). ")\n" foreach (sort keys %$dic);
