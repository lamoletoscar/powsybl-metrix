# 
# Copyright (c) 2021, RTE (http://www.rte-france.com)
# See AUTHORS.txt
# All rights reserved.
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, you can obtain one at http://mozilla.org/MPL/2.0/.
# SPDX-License-Identifier: MPL-2.0
# 

Test de DTVALDEP en variante de base sur un TD en angle imposé et curatif
--------------------------------------------------------------------------
Réseau identique à "variante_base_prise_td", mais le TD "FP.AND1  FTDPRA1  1"
est en angle imposé (DTMODREG = 2) et déclaré curatif sur l'incident 1
(DTNBDEFK = 1, DTPTDEFK = 1).

La variante de base (-1) le repositionne sur la prise 17 (une seule prise
d'écart : l'effet physique est négligeable). La variante 0 durcit le seuil N-k
de "FS.BIS1 FSSV.O1 2" pour rendre l'incident 1 contraignant, ce qui force la
création des variables curatives du TD.

En angle imposé, puiMin_ et puiMax_ sont définis égaux à la consigne (cf.
constructeur de TransformateurDephaseur). S'ils ne suivent pas le déphasage
imposé par la variante de base, ajouterContraintesBorneCuratif() pousse un
second membre négatif sur des variables positives ou nulles et le problème
devient infaisable : METRIX renvoie "Pas de solution trouvée" (compte rendu
C1 = 1) sur un cas qui se résout normalement.
