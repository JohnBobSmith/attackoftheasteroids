# Maintainer: David "JohnBobSmith" Bogner <myrunescapeemail609 AT gmail DOT com>
pkgname=attackoftheasteroids
pkgver=r22.c066496
pkgrel=1
pkgdesc="A.O.T.A - A simple 2D shooting and defense game."
arch=(x86_64)
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
}
