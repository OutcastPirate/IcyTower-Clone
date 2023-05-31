# PROI_PROJEKT

Autorzy:
- Jakub Kryczka
- Paweł Skorupski

## (WHAT)TODO
- podmiana tekstur na wyższych poziomach
- combosy
- jakieś ustawienia coś może?
- score board
- TESTY jednostkowe - player; platform; game?


## DONE
- **Basic menu**
- **poprawa optymalizacji zarządzania wyświetlaniem platform**
  - **Na starcie generowane jest jedynie 50 obiektów typu Tile; przy określonej różnicy wysokości do najniższej platformy; zachodzi zmiana wysokości => Przesunięce do góry oraz wylosowanie nowej pozycji na osi X oraz rozmiaru.**
  - **Zmiana maksymalnego rozmiaru platform wraz ze wzrostem wysokości; (co 50 tileów)**
- **Dodana obsługa dźwięku - soundtrack; na razie wykomentowane do momentu napisania - ew. znalezienia dobrej nutki.**
- **Dopracowane MENU. Ładniejsze przyciski; logo; refaktoryzacja kodu - Close żeby coś robił.**
- Obsługa kolizji z kolekcją obiektów typu Tile. (Player sprawdza kolejno ze wszystkimi Tile'ami czy nie koliduje)
- Wyłączanie aplikacji ~nie~ już działa
- Klasa "Tile" (platforma)
- odbijanie od ścian - poprawione
- losowa wielkość i położenie platform
- wyższe skoki uwarunkowane wcześniejszym rozpędzeniem się
- ambitniejsza obsługa końca gry niż "window.close()" jak się spadnie ERROR goes BRRRR
- Ruch kamery -> działa w miarę poprawnie, nie przesuwa się sama w razie bezczynności użytkownika
- Manager tekstur; każda tekstura jest załadowana w pamięci tylko raz.
- counter, działa ale no jest zrobiomy z płyty wiórowej i taśmy
- kolizja tylko z górną wartstwą platformy
- obługa kierunkowości klasy gracza i podmiana tekstur w zależności od kierunku i prędkości ruchu
- Klasa Game
