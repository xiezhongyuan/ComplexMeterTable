#ifndef TDMSUMMARYTABLEWGT_H
#define TDMSUMMARYTABLEWGT_H

#include <QTableWidget>
#include <QStyledItemDelegate>

#define ROWCOUNTPERPAGE 15
#define ROWHEIGHT 60//行高

class TDMSummaryTableWgt : public QTableWidget
{
    Q_OBJECT
public:
    explicit TDMSummaryTableWgt(QWidget *parent = 0);
    ~TDMSummaryTableWgt();

    /**
     * @brief appendRowData            添加一行数据到最后一行
     */
    void appendRowData();

signals:
    void sigViewBtnClicked(int i);

protected:
    /**
     * @brief resizeEvent               重载虚函数 resize事件，同时更新m_frozenTableWgt的位置
     * @param event
     */
    virtual void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

    /**
     * @brief moveCursor                重载虚函数 鼠标移动事件
     * @param cursorAction
     * @param modifiers
     * @return
     */
    virtual QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers) Q_DECL_OVERRIDE;

    /**
     * @brief scrollTo                  TableWidget移动事件
     * @param index
     * @param hint
     */
    void scrollTo (const QModelIndex & index, ScrollHint hint = EnsureVisible) Q_DECL_OVERRIDE;


private:
    /**
     * @brief initFrozenTable           初始化被冻结tableWidget
     */
    void initFrozenFrame();

    /**
     * @brief updateFrozenTableGeometry 更新被冻结的tableWidget位置
     */
    void updateFrozenTableGeometry();

    /**
     * @brief initFrame                 初始化显示内容的tableWidget
     */
    void initFrame();

private:
    QTableWidget *m_frozenTableWgt;// 使用TableWidget 作为header，并冻结

};

class ItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ItemDelegate(int type, QObject *parent=0);

    void paint(QPainter *painter,
               const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    int     m_type;//type=0: header    type=1：content
};


#endif // TDMSUMMARYTABLEWGT_H
