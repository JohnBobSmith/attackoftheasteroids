# Maintainer: David "JohnBobSmith" Bogner <myrunescapeemail609 AT gmail DOT com>
pkgname=attackoftheasteroids
pkgver=r10.4bed830
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
	install -D -m644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
	install -D -m755 "src/aota" "${pkgdir}/usr/bin/aota"
}
