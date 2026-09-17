Curative redispatching with negative costs and redispatching cost offset
------------------------------------------------------------------------

Same network as curatif_groupes, with FSSV.O11_G also allowed to act in curative, and REDISPOF = 100.
On contingency "FS.BIS1 FSSV.O1 1", line "FS.BIS1 FSSV.O1 2" is overloaded: FVALDI11_G is increased in curative
and FSSV.O11_G and/or FSSV.O12_G (same node, same efficiency) are decreased in curative.

The redispatching cost offset is added to the cost before applying the NULLCOST lower bound (0.5 by default):
a downward cost of -100 gives max(-100 + 100, 0.5) = 0.5 and a downward cost of -90 gives max(-90 + 100, 0.5) = 10,
so the merit order between negative costs is kept in curative.

Variant 0 : FSSV.O12_G (-100) is cheaper than FSSV.O11_G (-90), FSSV.O12_G is decreased in curative
Variant 1 : costs are swapped, FSSV.O11_G (-100) is decreased in curative
Variant 2 : FSSV.O12_G (-100) only produces 100 MW, it is decreased by 100 MW and FSSV.O11_G (-90) completes in curative
