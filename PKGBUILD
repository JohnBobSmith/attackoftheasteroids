# Maintainer: David "JohnBobSmith" Bogner <myrunescapeemail609 AT gmail DOT com>
pkgname=attackoftheasteroids
pkgver=r25.a9d2532
pkgrel=1
pkgdesc="A.O.T.A - A simple 2D shooting and defense game."
arch=(x86_64)
depends=('sfml')
makedepends=('git')
url="https://github.com/JohnBobSmith/attackoftheasteroids"
license=('MIT')
source=("git+https://github.com/JohnBobSmith/attackoftheasteroids.git")
md5sums=('SKIP')

pkgver() {
  cd "$pkgname"
  printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

build() {
	cd "$pkgname/src/"
	make
}

package() {
	cd "$pkgname"
	install -D -m644 License.md "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
	install -D -m755 "src/aota" "${pkgdir}/usr/bin/aota"
	install -D -m755 "textures/bg.png" "${pkgdir}/usr/share/${pkgname}/textures/bg.png"
	install -D -m755 "textures/bullet.png" "${pkgdir}/usr/share/${pkgname}/textures/bullet.png"
	install -D -m755 "textures/easyAsteroid.png" "${pkgdir}/usr/share/${pkgname}/textures/easyAsteroid.png"
	install -D -m755 "textures/laser.png" "${pkgdir}/usr/share/${pkgname}/textures/laser.png"
	install -D -m755 "textures/moonbase.png" "${pkgdir}/usr/share/${pkgname}/textures/moonbase.png"
	install -D -m755 "textures/shield.png" "${pkgdir}/usr/share/${pkgname}/textures/shield.png"
	install -D -m755 "textures/ui/help.png" "${pkgdir}/usr/share/${pkgname}/textures/ui/help.png"
	install -D -m755 "textures/ui/start.png" "${pkgdir}/usr/share/${pkgname}/textures/ui/start.png"
	install -D -m755 "textures/ui/quit.png" "${pkgdir}/usr/share/${pkgname}/textures/ui/quit.png"
	install -D -m755 "textures/ui/helppage.png" "${pkgdir}/usr/share/${pkgname}/textures/ui/helppage.png"
	install -D -m755 "fonts/ehsmb.ttf" "${pkgdir}/usr/share/${pkgname}/fonts/ehsmb.ttf"
	install -D -m755 "audio/sfx/bulletFire.wav" "${pkgdir}/usr/share/${pkgname}/audio/sfx/bulletFire.wav"
	install -D -m755 "audio/sfx/enemyDeath.wav" "${pkgdir}/usr/share/${pkgname}/audio/sfx/enemyDeath.wav"
	install -D -m755 "audio/sfx/laserFire.wav" "${pkgdir}/usr/share/${pkgname}/audio/sfx/laserFire.wav"
	install -D -m755 "audio/sfx/shieldImpact.wav" "${pkgdir}/usr/share/${pkgname}/audio/sfx/shieldImpact.wav"
	install -D -m755 "audio/music/mainMenuTheme.wav" "${pkgdir}/usr/share/${pkgname}/audio/music/mainMenuTheme.wav"
}
